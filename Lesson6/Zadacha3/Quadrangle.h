#pragma once

#include "Figure.h"

class Quadrangle : public Figure
{
private:
    std::string _name; //название
    double a, b, c, d; //стороны
    double A, B, C, D; //углы

public:

    Quadrangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D)
    {
        this->_name = name;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    void get_info() override
    {
        
    }
};
