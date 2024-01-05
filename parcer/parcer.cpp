
#include <iostream>
#include <fstream>
#include <string>

//template<class T>
class ini_parser
{
private:
    std::string str, filename;      
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