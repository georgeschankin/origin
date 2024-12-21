#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

class Data
{
    private:
        int a_;
                      
    public:    
        std::mutex m;

        Data(int a)
        {
            this->a_ = a;
        }

        void set(int a)
        {
            Data::a_ = a;
        }

        int get()
        {
            return Data::a_;
        }              
};

void swap1(Data& a1, Data& b1)
{
    std::lock(a1.m, b1.m);

    std::lock_guard l1(a1.m, std::adopt_lock);
    std::lock_guard l2(b1.m, std::adopt_lock);

    int tmp = a1.get();
    a1.set(b1.get());
    b1.set(tmp);

    std::cout << "a = " << a1.get() << std::endl;
    std::cout << "b = " << b1.get() << std::endl;
}

void swap2(Data& a1, Data& b1)
{
    std::scoped_lock l(a1.m, b1.m); 

    int tmp = a1.get();
    a1.set(b1.get());
    b1.set(tmp);

    std::cout << "a = " << a1.get() << std::endl;
    std::cout << "b = " << b1.get() << std::endl;
}

void swap3(Data& a1, Data& b1)
{
    std::unique_lock<std::mutex> l1(a1.m, std::defer_lock);
    std::unique_lock<std::mutex> l2(b1.m, std::defer_lock);
    l1.lock();
    l2.lock();

    int tmp = a1.get();
    a1.set(b1.get());
    b1.set(tmp);

    std::cout << "a = " << a1.get() << std::endl;
    std::cout << "b = " << b1.get() << std::endl;

    l1.unlock();
    l2.unlock();
}



int main()
{
    setlocale(LC_ALL, "Russian");

    Data a(10);
    Data b(25);

    std::cout << "Первоначально " << "a = " << a.get() << "; b = " << b.get() << std::endl;

    std::thread th1(swap1, std::ref(a), std::ref(b));   
    std::thread th2(swap2, std::ref(a), std::ref(b));   
    std::thread th3(swap3, std::ref(a), std::ref(b));

    th1.join();
    th2.join();
    th3.join();
}
