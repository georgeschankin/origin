#include <iostream>
#include <chrono>
#include <thread>

const int val = 10; //количество клиентов (параметр)

int Client(void)
{
    int count_clients = 0;
    std::cout << "ID потока = " << std::this_thread::get_id() << std::endl;
    for (int i = 0; i < val; i++)
    {
        count_clients++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Клиенты = " << count_clients << std::endl;
    }
    return count_clients;
}

void Operationist(void)
{
    int count_clients = Client();
    std::cout << "ID потока = " << std::this_thread::get_id() << std::endl;
    for (int i = val; i >= 0; i--)
    {
        count_clients--;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << "Операционисты = " << count_clients << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    std::thread th1(Client);
    //std::thread th2(Operationist);
    std::thread th2 = std::move(th1);
    th1 = std::thread(Operationist);

    th1.join();
    th2.join();

    return 0;
}