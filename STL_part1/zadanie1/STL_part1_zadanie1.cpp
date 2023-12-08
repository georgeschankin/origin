
#include <iostream>
#include <string>
#include <cstring>
#include <map>

class Result_Sort
{
public:
    int value_;
    std::string sym_;

    Result_Sort(int value, std::string sym)
    {
        this->value_ =  value;
        this->sym_ = sym;
    }

    Result_Sort() {}

    static void sort(Result_Sort* res, int size)
    {
        Result_Sort temp;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (res[j].value_ < res[j + 1].value_)
                {
                    temp = res[j];
                    res[j] = res[j + 1];
                    res[j + 1] = temp;
                }
            }
        }           

        for (int i = 0; i < size; i++)
        {
            std::cout << res[i].sym_ << ": " << res[i].value_ << std::endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    int value, mass_value[11]; //счетчик символов, массив счетчиков

    std::map<int, std::string> stroka;     

    stroka[0] = "H";
    stroka[1] = "e";
    stroka[2] = "l";
    stroka[3] = "l";
    stroka[4] = "o";
    stroka[5] = " ";
    stroka[6] = "w";
    stroka[7] = "o";
    stroka[8] = "r";
    stroka[9] = "l";
    stroka[10] = "d";

    for (int i = 0; i < stroka.size(); i++)
    {
        std::cout << stroka[i];
    }

    for (int i = 0; i < stroka.size(); i++)
    {
        value = 0;
        for (int j = 0; j < stroka.size(); j++)
        {
            if (stroka[i] == stroka[j])
            {
                value++;
            }
        }    
        mass_value[i] = value;
    }

    Result_Sort* result = new Result_Sort[stroka.size()];
    
    for (int i = 0; i < stroka.size(); i++)
    {
        result[i] = Result_Sort(mass_value[i], stroka[i]);
    }

    Result_Sort::sort(result, stroka.size());

    delete[] result;

    
    return 0;
}