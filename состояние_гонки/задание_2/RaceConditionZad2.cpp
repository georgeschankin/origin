#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <mutex>
#include <atomic>
#include <iterator>

const int num_threads = 8;
const int len_calc = 20;

int sum(int s)
{
    int sum;
    for (int i = 0; i < 20; i++)
    {
        sum += static_cast<int>(pow(i, i));
    }
    std::cout << sum;
    return sum;
}

void ProgressBar()
{
    std::vector<std::thread> thr;
    auto begin = std::chrono::steady_clock::now();
    
    int i;
    for (i = 0; i < num_threads; ++i)
    {        
        thr.push_back(std::thread(sum(i)));       
    }

    //std::vector<std::thread>::iterator it; 
    i = 0;  
    //for (it = thr.begin(); it != thr.end(); ++it)
    for(const auto& elem : thr)
    {
        std::cout << "Номер потока = " << ++i << "; " <<
            "ID потока = " << std::this_thread::get_id() << "; " << "Progress bar = " << &elem << "; ";
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "Time = " << elapsed_ms.count() << "; " << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    ProgressBar();

    return 0;
}