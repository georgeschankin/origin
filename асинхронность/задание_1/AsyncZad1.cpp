#include <iostream>
#include <list>
#include <thread>
#include <future>

int FindMin(int* a, int i, int n, std::promise<int> prom)
{
    int j, min;
    min = i;
    for (j = i + 1; j < n; j++) 
    {
        if (a[j] < min) min = j;
    }
    prom.set_value(min);
    return min;
}

void selection_sort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

void SelectionSort(int* arr, int size, std::promise<int> prom)
{   
    for (int i = 0; i < size - 1; i++)
    {      
        int min_index = std::async(std::launch::async, FindMin, &arr, i, size, prom); //почему жалуется на неправильный ввод?
        if (min_index != i)
        {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

int main()
{
    std::list<int> myList = { 30, 10, 20, 40, 50 };
    //std::thread th(selection_sort, &myList, myList.size()); [](auto x) { selection_sort; }, & myList, myList.size()
    //std::thread th([](auto x) { selection_sort; }, &myList, myList.size());

    //auto res = std::async(std::launch::async, std::move(selection_sort), &myList, myList.size());
    //auto res = std::async(std::launch::async, [](auto x) { selection_sort; }, &myList, myList.size());

    //th.join();

    std::promise<int> p;
    std::future<int> f;
    f = p.get_future();
    auto res1 = std::async(std::launch::async, FindMin, &myList, myList.size(), std::move(p)); //СПОСОБ 1. не пойму как тогда применить функцию selection_sort
    auto res2 = std::async(std::launch::async, selection_sort, &myList, myList.size()); //СПОСОБ 2. не пойму как в таком случае передать на вывод (value.get)
    auto res3 = std::async(std::launch::async, SelectionSort, &myList, myList.size(), std::move(p)); //СПОСОБ 3. можно ли так делать?
    //и почему во всех случаях жалуется на неправильный ввод?


    for(auto const &i:myList)
    {
        std::cout << i << " ";
    }

    return 0;
}