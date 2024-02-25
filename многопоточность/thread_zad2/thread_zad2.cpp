
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>

const int thread_val = 2, elem_val = 1000; //кол-во потоков, кол-во элементов в векторах
std::vector<int> vec1(elem_val), vec2(elem_val);

int main()
{  
    setlocale(LC_ALL, "ru");   
    
    auto start_time = clock();
    std::cout << "Количество аппаратных ядер = " << std::thread::hardware_concurrency() << std::endl;
    for (int i = 0; i < thread_val; i++)
    {
        for (int j = 0; j < elem_val; j++)
        {                      
            std::vector<int> vector_thread(thread_val);
            
            std::thread vector_thread[j](vec1.size()); //возникает ошибка. как элементам вектора присвоить значение потока?

            std::thread th1(vec1.size());
            std::thread th2(vec1.size());

            th1.join();
            th2.join();                     
        }
    }
    auto end_time = clock();
    std::cout << "2 потока: " << end_time - start_time << " тиков или " << ((float)(end_time - start_time)) / CLOCKS_PER_SEC << " секунд(ы)" << std::endl;   

    return 0;
}