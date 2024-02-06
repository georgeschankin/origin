// project_of_class.cpp: определяет точку входа для приложения.
//

#include "project_of_class.h"
#include <windows.h>
#include "Figure.h"
#include "Triangle.h"
#include "Right_Triangle.h"
#include "Equilateral_Triangle.h"
#include "Isosceles_Triangle.h"
#include "Quadrangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Romb.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //прямоугольный треугольник
    double a1 = 10, b1 = 20, c1 = 30;
    double A1 = 50, B1 = 60, C1 = 90;
    std::string name1 = "Прямоугольный треугольник";

    if (C1 == 90)
    {
        //Figure* p1 = nullptr;
        Right_Triangle t1(name1, a1, b1, c1, A1, B1, C1);
        //p1 = &t1;
        t1.get_info();
    }
    else
    {
        std::cout << "введите угол С равным 90 градусов" << std::endl;
    }

    std::cout << "\n";

    //Равносторонний треугольник
    double a2 = 30, b2 = 30, c2 = 30;
    double A2 = 60, B2 = 60, C2 = 60;
    std::string name2 = "Равносторонний треугольник";
    if ((A2 == 60) && (B2 == 60) && (C2 == 60) && (a2 == b2) && (b2 == c2) && (a2 == c2))
    {
        //Figure* p2 = nullptr;
        Equilateral_Triangle t2(name2, a2, A2);
        //p2 = &t2;
        t2.get_info();
    }
    else
    {
        std::cout << "стороны должны быть равны и углы должны быть равны 60 градусов" << std::endl;
    }

    std::cout << "\n";

    //Равнобедренный треугольник
    double a3 = 30, b3 = 20, c3 = 30;
    double A3 = 70, B3 = 60, C3 = 70;
    std::string name3 = "Равнобедренный треугольник";
    if ((A3 == C3) && (a3 == c3))
    {
        //Figure* p3 = nullptr;
        Isosceles_Triangle t3(name3, a3, b3, A3, B3);
        //p3 = &t3;
        t3.get_info();
    }
    else
    {
        std::cout << "стороны а и с должны быть равны и углы А и С должны быть равны" << std::endl;
    }

    std::cout << "\n";

    //Квадрат
    double a4 = 30, b4 = 30, c4 = 30, d4 = 30;
    double A4 = 90, B4 = 90, C4 = 90, D4 = 90;
    std::string name4 = "Квадрат";
    if ((A4 == C4) && (C4 == B4) && (B4 == D4) && (A4 == D4) && (a4 == c4) && (c4 == b4) && (b4 == d4) && (a4 == d4))
    {
        //Figure* p4 = nullptr;
        Square t4(name4, a4, A4);
        //p4 = &t4;
        t4.get_info();
    }
    else
    {
        std::cout << "стороны должны быть равны и углы должны быть равны 90 градусов" << std::endl;
    }

    std::cout << "\n";

    //параллелограмм
    double a5 = 30, b5 = 20, c5 = 30, d5 = 20;
    double A5 = 50, B5 = 60, C5 = 50, D5 = 60;
    std::string name5 = "Параллелограмм";
    if ((A5 == C5) && (B5 == D5) && (a5 == c5) && (b5 == d5))
    {
        //Figure* p5 = nullptr;
        Parallelogram t5(name5, a4, b4, A4, B4);
        //p5 = &t5;
        t5.get_info();
    }
    else
    {
        std::cout << "стороны должны быть равны и углы должны быть равны 90 градусов" << std::endl;
    }

    std::cout << "\n";

    //Ромб
    double a6 = 30, b6 = 30, c6 = 30, d6 = 30;
    double A6 = 70, B6 = 50, C6 = 70, D6 = 50;
    std::string name6 = "Ромб";
    if ((A6 == C6) && (B6 == D6) && (a6 == c6) && (c6 == b6) && (b6 == d6))
    {
        //Figure* p6 = nullptr;
        Romb t6(name6, a6, A6, B6);
        //p6 = &t6;
        t6.get_info();
    }
    else
    {
        std::cout << "стороны должны быть равны и углы попарно должны быть равны" << std::endl;
    }
	return 0;
}
