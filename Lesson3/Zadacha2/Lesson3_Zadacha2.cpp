#include <iostream>
#include <string>
#include <Windows.h>

class Counter
{
private:
    int a;
    std::string command;

public:
    Counter(int a, std::string command)
    {
        this->a = a;
        this->command = command;
    }

    int work()
    {
        setlocale(LC_ALL, "Russian");
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);
        if (command == "+")
        {
            a++;
        }
        else if (command == "-")
        {
            a--;
        }
        else if (command == "=")
        {
            return a;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::string yes_no;
    std::string command_;
    int a_;

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

    Counter counter(); //если убрать () или поставить {} вознкает ошибка
    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command_;
        Counter counter(a_, command_);
        if ((command_ == "+") || (command_ == "-"))
        {
            a_ = counter.work();
            continue;
        }
        else if (command_ == "=")
        {
            std::cout << counter.work() << std::endl;
            continue;
        }
        else if (command_ == "x")
        {
            std::cout << "До свидания" << std::endl;
            break;
        }

    } while (true);

}


