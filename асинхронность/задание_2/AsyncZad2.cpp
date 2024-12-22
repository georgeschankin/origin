#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

int block = 4;

void func(int& a)
{
    a++;
}

template <typename Iterator>
void parallelForEachAsyncRecursive(Iterator begin, Iterator end)
{   
    auto size = std::distance(begin, end);

    if (size <= block)
    {
        std::for_each(begin, end, func);
    }
    else
    {
        auto mid = begin;      
        mid += size / 2;
        auto ftRes = std::async(parallelForEachAsyncRecursive<Iterator>, begin, mid);
        parallelForEachAsyncRecursive(mid, end);

        ftRes.get();
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << "Первоначальный: ";
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    parallelForEachAsyncRecursive(vec.begin(), vec.end());

    std::cout << "\nПосле: ";
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
