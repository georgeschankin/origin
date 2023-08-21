#include "Counter.h"

Counter::Counter(int a)
    {
        this->a = a;
    }

    void Counter::plus()
    {
        this->a++;
        //return a;
    }

    void Counter::minus()
    {
        this->a--;
        //return a;
    }

    int Counter::ravno()
    {
        return a;
    }
