#pragma once

#include "Figure.h"
#include "Quadrangle.h"

class Rectangle : public Quadrangle
{
public:

    Rectangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(name, a, b, c, d, A, B, C, D)
    {

    }
};
