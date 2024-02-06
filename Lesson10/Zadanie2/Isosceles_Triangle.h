#pragma once

#include "Triangle.h"
#include "Figure.h"

class Isosceles_Triangle : public Triangle
{
public:

    Isosceles_Triangle(std::string name, double a, double b, double A, double B) : Triangle(name, a, b, a, A, B, A)
    {

    }
};