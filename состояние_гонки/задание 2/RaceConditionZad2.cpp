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
        sum += pow(i, i);
    }
    return sum;
}

void ProgressBar()
{
    std::vector<std::thread> thr;
    auto begin[num_threads];
    auto end[num_threads];
    int i;
    for (i = 0; i < num_threads; ++i)
    {
        begin[i] = std::chrono::steady_clock::now();
        thr.push_back(std::thread(sum(i)));
        end[i] = std::chrono::steady_clock::now();
    }

    std::vector<std::thread>::iterator it;
    i = 0;
    for (it = thr.begin(); it != thr.end(); ++it)
    {
        std::cout << "Номер потока = " << ++i << "; " <<
            "ID потока = " << std::this_thread::get_id() << "; " << "Progress bar = " << &it << "; "
            << "Time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin) << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    ProgressBar();

    return 0;
}