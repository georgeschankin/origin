
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>

const int thread_val = 2, elem_val = 1000; //кол-во потоков, кол-во элементов в векторах (поменяйте значения для других парметров)

template<typename T>
int sum(const std::vector<T>& A)
{
    int val = 0;
    for (std::vector<int>::iterator it = A.begin(); it != A.end(); it++)
    {
        val++;
    }
    return val;
}

int main()
{  
    setlocale(LC_ALL, "ru");   
    std::vector<int> vec1(elem_val), vec2(elem_val);

    for (int i = 0; i < elem_val; i++)
    {
        vec1.push_back(i);
        vec2.push_back(i);
    }
    
    auto start_time = clock();
    std::cout << "Количество аппаратных ядер = " << std::thread::hardware_concurrency() << std::endl;
    for (int i = 0; i < thread_val; i++)
    {
        for (int j = 0; j < elem_val; j++)
        {                      
            std::vector<int> vector_thread(thread_val);
                       
            std::thread th1(sum(vec1), sum(vec2)); //для одного потока
            std::thread th2(sum(vec1), sum(vec2)); //для двух потоков
            //std::thread th3(sum(vec1), sum(vec2)); 
            //std::thread th4(sum(vec1), sum(vec2)); 
            //std::thread th5(sum(vec1), sum(vec2)); 
            //std::thread th6(sum(vec1), sum(vec2)); 
            //std::thread th7(sum(vec1), sum(vec2)); 
            //std::thread th9(sum(vec1), sum(vec2)); 
            //std::thread th10(sum(vec1), sum(vec2)); 
            //std::thread th11(sum(vec1), sum(vec2)); 
            //std::thread th12(sum(vec1), sum(vec2)); 
            //std::thread th13(sum(vec1), sum(vec2)); 
            //std::thread th14(sum(vec1), sum(vec2)); 
            //std::thread th15(sum(vec1), sum(vec2)); 
            //std::thread th16(sum(vec1), sum(vec2)); 
           
            th1.join();
            th2.join();
            //th3.join();
            //th4.join();
            //th5.join();
            //th6.join();
            //th7.join();
            //th8.join();
            //th9.join();
            //th10.join();
            //th11.join();
            //th12.join();
            //th13.join();
            //th14.join();
            //th15.join();
            //th16.join();
        }
    }
    auto end_time = clock();
    std::cout << thread_val << " потока(ов): " << end_time - start_time << " тиков или " << ((float)(end_time - start_time)) / CLOCKS_PER_SEC << " секунд(ы)" << std::endl;

    return 0;
}