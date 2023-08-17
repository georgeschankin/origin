#pragma once
class Counter
{
private:
    int a;

public:
    Counter(int a_)
    {
        this->a = a_;
    }

    void plus()
    {
        this->a++;
        //return a;
    }

    void minus()
    {
        this->a--;
        //return a;
    }

    int ravno()
    {
        return a;
    }
};