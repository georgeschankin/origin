
#include <iostream>
#include <vector>
#include <Windows.h>

template<typename T>
class Functor
{
public:

    int get_sum(const Functor<T>& A)
    {
        int res = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 3)
            {
                res += A[i];
            }
        }
        return res;
    }

    int get_count(const Functor<T>& A)
    {
        int res = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 3)
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<int> B {4, 1, 3, 6, 25, 54};
    
    Functor functor; //не пойму почему переменная не принимает тип класса
    functor = std::foreach(B.begin(), B.end(), functor); //какую директиву надо подключить, чтобы эта команда заработала?

    std::cout << std::endl;
    std::cout << "get_sum() = " << functor.get_sum() << std::endl;
    std::cout << "get_count() = " << functor.get_count(B) << std::endl;

    return 0;
}
