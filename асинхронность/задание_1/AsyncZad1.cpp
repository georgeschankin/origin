#include <iostream>
#include <list>
#include <thread>
#include <future>

void FindMin(int* a, int i, int n, std::promise<int> prom)
{
    int j, min;
    min = i;
    for (j = i + 1; j < n; j++) 
    {
        if (a[j] < a[min]) min = j;
    }
    prom.set_value(min);  
}

template<typename Container>
void FindMin2(Container& a, int i, const int n, std::promise<int> prom)
{
    int j, min;
    min = i;
    for (j = i + 1; j < n; j++)
    {
        if (a[j] < a[min]) min = j;
    }
    prom.set_value(min);
}

void SelectionSort(int* arr, int size)
{         
    for (int i = 0; i < size - 1; i++)
    { 
        std::promise<int> p;
        std::future<int> f = p.get_future();
        auto res = std::async(std::launch::async, FindMin, arr, i, size, std::move(p));    
        //f.wait();
        int min_index = f.get();
        if (min_index != i)
        {
            std::swap(arr[i], arr[min_index]);
        }
    }   
}

template<typename Container/*, class T*/>
void SelectionSort2(Container& arr, /*T& elem,*/ const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        std::promise<int> p;
        std::future<int> f = p.get_future();
        auto res = std::async(std::launch::async, FindMin2, arr, i, size, std::move(p));
        //f.wait();
        int min_index = f.get();
        if (min_index != i)
        {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

int main()
{
    std::vector<int> myList1 = { 30, 10, 20, 40, 50 };
    int myList2[5] = { 30, 10, 20, 40, 50 };
    
    SelectionSort(myList2, sizeof(myList2)/sizeof(int));
    SelectionSort2(myList1, myList1.size());

    for(auto const &i:myList2)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (auto const& i : myList1)
    {
        std::cout << i << " ";
    }

    return 0;
}