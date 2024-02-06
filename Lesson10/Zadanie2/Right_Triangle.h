#pragma once

#include "Triangle.h"
#include "Figure.h"

class Right_Triangle : public Triangle
{
public:

    Right_Triangle(std::string name, double a, double b, double c, double A, double B, double C) : Triangle(name, a, b, c, A, B, C)
    {

    }
};