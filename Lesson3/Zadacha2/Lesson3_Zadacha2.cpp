﻿#include <iostream>
#include <string>
#include <Windows.h>

class Counter
{
private:
    int a;
   
public:
    Counter(int a_)
    {
        this->a = a_;        
    }

    void plus()
    {      
        this-> a++;
        //return a;
    }

    void minus()
    {
        this-> a--;
        //return a;
    }

    int ravno()
    {
        return a;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::string yes_no;
    std::string command_;
    int a_, i = 0;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> yes_no;

    std::cout << "\n";

    if (yes_no == "да")
    {
        std::cout << "Введите начальное значение счетчика ";
        std::cin >> a_;
    }
    else if (yes_no == "нет")
    {
        a_ = 1;
    }
    else
    {
        a_ = 0;
    }

    Counter counter(a_); //если убрать () или поставить {} вознкает ошибка
    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command_;
       // Counter counter(a_);

        if (command_ == "+")
        {
            /*a_ =*/ counter.plus();
            continue;           
        }
        else if (command_ == "-")
        {
            /*a_ =*/ counter.minus();
            continue;            
        }
        else if (command_ == "=")
        {
            std::cout << counter.ravno() << std::endl;
            continue;           
        }
        else if (command_ == "x")
        {
            std::cout << "До свидания" << std::endl;
            break;
        } 
        i++;
        std::cout << i << std::endl;
    } while (command_ != "x");
    
}


