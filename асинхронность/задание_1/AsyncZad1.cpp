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

//template<typename Container>
int FindMin2(const std::list<int> a, int i, int n, std::promise<int> prom)
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

void SelectionSort(int* arr, int size, std::promise<int> prom)
{   
    for (int i = 0; i < size - 1; i++)
    {      
        auto res = std::async(std::launch::async, FindMin, arr, i, size, std::move(prom)); //почему жалуется на неправильный ввод?
        int min_index = res.get();
        if (min_index != i)
        {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

//template<typename Container>
void SelectionSort2(std::list<int> arr, int size, std::promise<int> prom)
{
    for (int i = 0; i < size - 1; i++)
    {
        auto res = std::async(std::launch::async, FindMin2, arr, i, size, std::move(prom)); //почему жалуется на неправильный ввод?
        int min_index = res.get();
        if (min_index != i)
        {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

int main()
{
    //std::list<int> myList = { 30, 10, 20, 40, 50 };
    int myList[5] = { 30, 10, 20, 40, 50 };

    //std::thread th(selection_sort, &myList, myList.size()); [](auto x) { selection_sort; }, & myList, myList.size()
    //std::thread th([](auto x) { selection_sort; }, &myList, myList.size());

    //auto res = std::async(std::launch::async, std::move(selection_sort), &myList, myList.size());
    //auto res = std::async(std::launch::async, [](auto x) { selection_sort; }, &myList, myList.size());

    //th.join();

    std::promise<int> p;
    std::future<int> f;
    f = p.get_future();
    
    SelectionSort(myList, 5, std::move(p)); //способ1 стандартные функции и через массив

    SelectionSort2(myList, myList.size(), std::move(p)); //способ 2 через контейнеры
    //не понимаю почему оба способа не работают, пробовал еще шаблонные функции сделать

    for(auto const &i:myList)
    {
        std::cout << i << " ";
    }

    return 0;
}