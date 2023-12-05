
#include <iostream>
#include <vector>
#include <Windows.h>

template<class T>
T squaring(T a)
{
    return a * a;
}

template<typename T>
std::vector<T> squaring(const std::vector<T>& A)
{
    std::vector<T> res;
    for (int i = 0; i < A.size(); i++)
    {
        res.push_back(A[i] * A[i]); //почему-то программа не запускается, подозреваю что ошибка в присвоении данному вектору, подскажите, пожалуйста, если я верно понял ошибку, как решить это не применяя класс?
    }
    return res;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //задание 1
    int a;
    std::vector<int> A {1, 2, 3, 4, 5};
    std::cout << "Введите число ";
    std::cin >> a;

    std::cout << "Результат " << squaring(a) << std::endl;

    std::cout << "Вектор ";
    for (int i = 0; i < A.size(); i++)
    {
        std::cout << A[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "Вектор возведенный в квадрат ";
    for (int i = 0; i < squaring(A).size(); i++)
    {
        std::cout << squaring(A)[i] << " ";
    }
}
