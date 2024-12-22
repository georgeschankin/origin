#include "Timer.h"

#include <vector>
#include <thread>
#include <mutex>

const int num_threads = 8;
const int len_calc = 20;
std::mutex m1, m2, m3, m4;

std::once_flag flag;

void ProgressBar(int NumThread)
{
    //auto begin = std::chrono::steady_clock::now();
    m1.lock();
    Timer t1;
    consol_parameter d1;
    m1.unlock();

    //std::cout << NumThread + 1 << "\t" << "         " << std::this_thread::get_id() << "\t" << std::endl;
    m2.lock();
    d1.SetPosition(0, NumThread + 1);
    std::cout << NumThread + 1 << "         " << "\t" << std::this_thread::get_id() << "\t";
    m2.unlock();

    for (int i = 0; i < len_calc; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        m3.lock();
        d1.SetPosition(i + 27, NumThread + 1);
        std::cout << char(218);
        m3.unlock();
    }
    m4.lock();

    /*auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    d1.SetPosition(47, NumThread + 1);
    std::cout << "           " << elapsed_ms.count() << "\t" << std::endl;*/
    d1.SetPosition(55, NumThread + 1);
    t1.print();
    m4.unlock();
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

    
    std::cout << "\n\n\n";
    return 0;
}