
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>

std::vector<int> num_threads{ 1, 2, 4, 8, 16 }; // вектор кол-ва потоков
std::vector<int> size_vector{ 1000, 10000, 100000, 1000000 }; // вектор количества элементов векторов

void sum(int& sum, const std::vector<int> newV1, const std::vector<int> newV2)
{
    for (int i = 0; i < newV1.size(); ++i)
    {
        sum += newV1.at(i) + newV2.at(i);
    }
}

int main()
{  
    setlocale(LC_ALL, "ru");   
    std::vector<int> vec1, vec2;
      
    std::cout << "Количество аппаратных ядер = " << std::thread::hardware_concurrency() << std::endl;

    for (auto& T : num_threads)
    {
        std::cout << std::endl << T << " поток(и)";
        for (auto& V : size_vector)
        {
            vec1.resize(V, 2);
            vec2.resize(V, 5);
            std::vector<std::thread> threads;
            int sumV = 0;
            int part_size = V / T;
            auto start_time = clock();
            for (int i = 0; i < T; i++)
            {
                std::vector<int> newVector1;
                std::vector<int> newVector2;               
              
                newVector1.push_back(vec1.at(i));
                newVector2.push_back(vec2.at(i));
                            
                threads.push_back(std::thread(sum, std::ref(sumV), newVector1, newVector2));
            }
            for (auto& it : threads)
            {
                it.join();
            }
            auto end_time = clock();
            std::cout << T << " потока(ов): и " << V << " элементов " << end_time - start_time << " тиков или " << ((float)(end_time - start_time)) / CLOCKS_PER_SEC << " секунд(ы)" << std::endl;
        }
        std::cout << "\n";
    }
    
    return 0;
}