#include <iostream>
#include "Triangle.h"

void Triangle::get_info()
{
    std::cout << _name << std::endl;
    std::cout << "�������: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << std::endl;
    std::cout << "����: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;
}