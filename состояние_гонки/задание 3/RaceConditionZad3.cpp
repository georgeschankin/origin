#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

class Data
{
    private:
        int a_;
        std::mutex m;

        void set(int a)
        {
            Data::a_ = a;
        }

        int get()
        {
            return Data::a_;
        }
        
    public:
        
        Data(int a)
        {
            this->a_ = a;
        }
       
        friend void swap1(Data& a1, Data& b1)
        {
            std::lock(a1.m, b1.m);

            int tmp = a1.get();
            a1.set(b1.get());
            b1.set(tmp);
            
            std::cout << "a = " << a1.get() << std::endl;
            std::cout << "b = " << b1.get() << std::endl;

            a1.m.unlock();
            b1.m.unlock();
        }

        friend void swap2(Data& a1, Data& b1)
        {
            std::scoped_lock l(a1.m, b1.m); //почему не работает?

            int tmp = a1.get();
            a1.set(b1.get());
            b1.set(tmp);

            std::cout << "a = " << a1.get() << std::endl;
            std::cout << "b = " << b1.get() << std::endl;
        }

        friend void swap3(Data& a1, Data& b1)
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
};



int main()
{
    Data a(10);
    Data b(25);

    std::thread th1(swap1(a, b));
    std::thread th2(swap2(a, b));
    std::thread th3(swap3(a, b));

    th1.join();
    th2.join();
    th3.join();
}
