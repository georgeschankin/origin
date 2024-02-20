
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>



int main()
{
    std::vector<int> vec1 (1000), vec2(1000);
    
    std::cout << "Количество аппаратных ядер = " << std::thread::hardware_concurrency() << std::endl;

    std::thread th1(vec1.size());
    auto start_thread1 = std::chrono::steady_clock::now();
    auto end_thread1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_thread1 = end_thread1 - start_thread1;
    std::cout << "1 потоков: " << time_thread1.count() << "\t";

    std::thread th2(vec2.size());
    auto start_thread2 = std::chrono::steady_clock::now();
    auto end_thread2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_thread2 = end_thread2 - start_thread2;
    std::cout << "1 потоков: " << time_thread2.count() << "\t";
   
    th1.join();
    th2.join();

    return 0;
}