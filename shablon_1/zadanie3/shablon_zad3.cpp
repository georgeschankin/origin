
#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>


class Functor
{
private:
    int sum = 0, count = 0;
    
public: 
    void operator() (int A)
    {             
        if (A % 3 == 0)
        {
            sum += A;
            count++;
        }                     
    }

    int get_sum() const { return sum; }

    int get_count() const { return count; }   
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<int> B {4, 1, 3, 6, 25, 54};
    
    Functor functor;
    functor = std::for_each(B.begin(), B.end(), functor);

    std::cout << "get_sum() = " << functor.get_sum() << std::endl;
    std::cout << "get_count() = " << functor.get_count() << std::endl;

    return 0;
}
