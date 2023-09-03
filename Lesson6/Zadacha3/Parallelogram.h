#pragma once

#include "Figure.h"
#include "Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:

    Parallelogram(std::string name, double a, double b, double A, double D) : Quadrangle(name, a, b, a, b, A, D, A, D)
    {

    }
};
