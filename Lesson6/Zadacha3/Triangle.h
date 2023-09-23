#pragma once

#include "Figure.h"

class Triangle : public Figure
{
private:
    std::string _name; //��������
    double a, b, c; //�������
    double A, B, C; //����

public:

    Triangle(std::string name, double a, double b, double c, double A, double B, double C) : Figure(name, a, b, c, 0, A, B, C, 0)
    {
        this->_name = name;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    void get_info()
    {
        
    }

};
