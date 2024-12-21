#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

const int num_threads = 8;
const int len_calc = 20;
std::mutex m;

void ProgressBar(int NumThread)
{
    auto begin = std::chrono::steady_clock::now();
    
    std::cout << NumThread + 1 << "\t" << "         " << std::this_thread::get_id() <<  "\t" << std::endl;
    for (int i = 0; i < len_calc; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        m.lock();
        std::cout << char(218);
        m.unlock();
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << elapsed_ms.count() << "\t" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    std::cout << "Номер потока\t" << "ID потока\t" << "Progress bar\t\t" << "Time" << std::endl;
    std::vector<std::thread> vectorThreads(num_threads);
    for (int i = 0; i < num_threads; i++)
    {
        vectorThreads[i] = std::thread(ProgressBar, i);
    }
    for (auto& i : vectorThreads)
    {
        i.join();
    }

    return 0;
}