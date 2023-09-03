#pragma once

#include "Figure.h"
#include "Quadrangle.h"

class Romb : public Quadrangle
{
public:

    Romb(std::string name, double a, double A, double B) : Quadrangle(name, a, a, a, a, A, B, A, B)
    {

    }
};