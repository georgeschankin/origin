#include "Ini_Parser.h"

bool Ini_Parser::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void Ini_Parser::read()
{   
    int str_sec = 0, str_name_val = 0;

    f_in.open(file);
    if (!f_in.is_open())
    {
        throw std::out_of_range("���� �� ������");
    }

    //������ ���� ���������
    while (std::getline(f_in, str))
    {
        std::string substr_upequial; //��������� �� =
        std::string substr_afterequial; //��������� ����� =
        if (str.at(0) == '[') //������ ������
        {          
            str.erase(str.find('['), 1);
            str.erase(str.find(']'), 1);
            section.push_back(str);           
        }
        else if(str.at(0) == ';') //�����������
        {
            continue;
        }
        else //������ ���������� (�� �������� � ��������)
        {           
            for (size_t i = 0; i < str.length(); i++)
            {
                if (str.at(i) == ';') //����������� �� ����������
                {
                    str.erase(str.find(';'));
                    if (str.at(i) != '=' && str.at(i) == ' ') //������ ��������
                    {                    
                        substr_upequial += str[i];  
                        if(str.at(i) == ' ') str.erase(str.find(' '));
                    }                  
                    else //������ ��������
                    {
                        substr_afterequial += str[i];
                        if (str.at(i) == ' ') str.erase(str.find(' '));
                    }               
                }
                else if (str.find('=') == std::string::npos)
                {
                    throw std::out_of_range("���������� �� ����� ��������");
                }
                else
                {
                    if (str.at(i) != '=')
                    {
                        substr_upequial += str[i];
                    }
                    else
                    {
                        substr_afterequial += str[i];
                    }                   
                }
            }       
        }
        nameval.push_back(substr_upequial);
        val.push_back(substr_afterequial);
        section_name_value.insert(make_pair(section[str_sec]), make_pair(nameval[str_name_val], val[str_name_val]));
        str_sec++;
        str_name_val++;
    }    
}

//����� ����������� �������� � ���� int � double
template<class T>
T Ini_Parser::get_value(std::string section, std::string var)
{
    read();

    T n;

    for (auto it = section_name_value.begin(); it != section_name_value.end(); ++it)
    {
        if (it.first == section)
        {
            if (it.second.first == var)
            {
                if (is_number(it.second.second))
                {
                    n = stoi(it.second.second);
                }
                else
                {
                    n = stod(it.second.second);
                }
            }
        }
    }
    return n;
}

// ����� ������������ �������� � ���� string	
std::string Ini_Parser::get_value(std::string section, std::string var)
{
    read();

    std::string res = "";

    for (auto it = section_name_value.begin(); it != section_name_value.end(); ++it)
    {
        if (it.first == section)
        {
            if (it.second.first == var)
            {
                res = it.second.second;
            }
        }
    }
    return res;
}