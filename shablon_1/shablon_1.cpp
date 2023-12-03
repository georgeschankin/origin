
#include <iostream>
#include <vector>

//задание 1 можно ли это задание сделать не создавая класс ?
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
        res.insert(i, A[i] * A[i]); //почему-то программа не запускается, подозреваю что ошибка в присвоении данному вектору, подскажите, пожалуйста, если я верно понял ошибку, как решить это не применяя класс?
    }
    return res;
}

//задание 2
template<typename T>
class Table
{
public:
    int l, c;
    Table(int unsigned line, int unsigned column)
    {
        this->l = line;
        this->c = column;
    }

    Table<T>& operator [](int unsigned a, int unsigned b) //не понимаю что я мог здесь неправильно объявить?
    {
         return *this[a][b];
    }

    const Table<T>& operator [](const unsigned int a, const unsigned int b) const
    {
        return *this[a][b];
    }
};

//задание 3
template<class T>
T get_sum(const std::vector<T>& A)
{
    T res = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] % 3)
        {
            res += A[i];
        }
    }
    return res;
}

template<class T>
T get_count(const std::vector<T>& A)
{
    int unsigned res = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] % 3)
        {
            res++;
        }
    }
    return res;
}


int main()
{
    //задание 1
    int a;
    std::vector<int> A {1, 2, 3, 4, 5};
    std::cout << "Введите число ";
    std::cin >> a;

    std::cout << "Результат " << squaring(a) << std::endl;
    
    std::cout << "Вектор ";
    for (int i = 0; i < A.size(); i++)
    {
        std::cout << A[i];
    }
    squaring(A);

    //задание 2
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0];

    //задание 3
    std::vector<int> B {4, 1, 3, 6, 25, 54};
    std::cout << "Вектор ";
    for (int i = 0; i < B.size(); i++)
    {
        std::cout << B[i];
    }
    std::cout << "get_sum() = " << get_sum << std::endl; //это задание тоже через класс надо делать? не выводит результат через <<
    std::cout << "get_count() = " << get_count << std::endl;

    return 0;
}
