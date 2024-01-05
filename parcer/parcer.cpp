
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

//template<class T>
class ini_parser
{
private:
    std::string str, filename;  
    std::vector<std::string> sections;
    std::vector<std::string> values;
    std::multimap<std::string, std::pair<std::string, std::string>> section_name_value;
    std::ifstream file;

public:
    ini_parser(std::string filename)
    {
        this->filename = filename;
    }
    
    template<class T>
    T get_value(std::string section, std::string number)
    {       
        T num;
       
        file.open(filename);
        if (!file.is_open())
        {
            std::cout << "файл не открыт" << std::endl;           
        }
        else
        {
            while (!file.eof())
            {
                file >> str;
                file >> num;
                if (str == ("[" + section + "]"))
                {
                    if (num == number)
                    {                        
                        file.close();
                        num = number;
                        break;
                    }                                        
                }                    
            }
        }
        return num;
    }   
};

int main()
{   
    setlocale(LC_ALL, "Russian");

    ini_parser parser("file_parcer.ini");
    auto value = parser.get_value<std::string>("section.2", "var2");

    return 0;
}