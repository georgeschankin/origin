#pragma once

#include "Triangle.h"
#include "Figure.h"
#include <iostream>

class Equilateral_Triangle : public Triangle
{
public:

    Equilateral_Triangle(std::string name, double a, double A) : Triangle(name, a, a, a, A, A, A)
    {

    }
};
