#pragma once

#include "Figure.h"
#include "Quadrangle.h"

class Square : public Quadrangle
{
public:

    Square(std::string name, double a, double A) : Quadrangle(name, a, a, a, a, A, A, A, A)
    {

    }
};