#include <iostream>
#include "Quadrangle.h"
#include "Figure.h"

void Quadrangle::get_info()
{
    std::cout << _name << std::endl;
    std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << " " << "d = " << d << std::endl;
    std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << " " << "D = " << D << std::endl;
}