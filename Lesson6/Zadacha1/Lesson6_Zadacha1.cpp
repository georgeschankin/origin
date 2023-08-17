
#include <iostream>
#include "functions.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    int a, b;//числа
    int operation;//операция

    std::cout << "Введите первое число: " << std::endl;
    std::cin >> a;
    std::cout << "Введите второе число: " << std::endl;
    std::cin >> b;

    std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): " << std::endl;
    std::cin >> operation;

    switch (operation)
    {
    case 1:
        std::cout << a << " плюс " << b << " = " << plus(a, b) << std::endl;
        break;
    case 2:
        std::cout << a << " минус " << b << " = " << minus(a, b) << std::endl;
        break;
    case 3:
        std::cout << a << " умножить на " << b << " = " << multiplication(a, b) << std::endl;
        break;
    case 4:
        std::cout << a << " делить на " << b << " = " << division(a, b) << std::endl;
        break;
    case 5:
        std::cout << a << " в степени " << b << " = " << exp(a, b) << std::endl;
        break;
    default:
        break;
    }
}