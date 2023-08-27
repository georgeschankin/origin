#include <iostream>

class Figure
{
private:
    std::string _name; //название
    double a, b, c, d; //стороны
    double A, B, C, D; //углы
    
public:
    /*int get_sides_count()
    {
        return _side;
    }

    std::string get_name()
    {
        return _name;
    }*/

    
    Figure(std::string name, double a, double b, double c, double d, double A, double B, double C, double D)
    {
        this->_name = name;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    
    Figure()
    {}

    void get_triangle()
    {
        std::cout << _name << std::endl;
        std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << std::endl;
        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;
    }

    void get_quadrangle()
    {
        std::cout << _name << std::endl;
        std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << " " << "d = " << d << std::endl;
        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << " " << "D = " << D << std::endl;
    }

};

class Triangle : public Figure
{

public:
    
    Triangle(std::string name, double a, double b, double c, double A, double B, double C) : Figure ( name, a, b, c, 0, A, B, C, 0)
    {
        
    }
    
};

class Right_Triangle : public Triangle
{
public:
    
    Right_Triangle(std::string name, double a, double b, double c, double A, double B, double C) : Triangle(name, a, b, c, A, B, C)
    {

    }
    
};

class Isosceles_Triangle : public Triangle
{
public:    

    Isosceles_Triangle(std::string name, double a, double b, double A, double B) : Triangle(name, a, b, a, A, B, A)
    {
        
    }
};

class Equilateral_Triangle : public Triangle
{
public:
    
    Equilateral_Triangle(std::string name, double a, double A) : Triangle(name, a, a, a, A, A, A)
    {

    }
};

class Quadrangle : public Figure
{
public:
    
    Quadrangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D)
    {
        
    }
};

class Rectangle : public Quadrangle
{
public:    

    Rectangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(name, a, b, c, d, A, B, C, D)
    {

    }
};

class Square : public Quadrangle
{
public:    

    Square(std::string name, double a, double A) : Quadrangle(name, a, a, a, a, A, A, A, A)
    {

    }
};

class Parallelogram : public Quadrangle
{
public:
    
    Parallelogram(std::string name, double a, double b, double A, double D) : Quadrangle(name, a, b, c, b, A, B, A, B)
    {

    }
};

class Romb : public Quadrangle
{
public:
    
    Romb(std::string name, double a, double A, double B) : Quadrangle(name, a, a, a, a, A, B, A, B)
    {

    }
};

void print_info(void (*fp)())
{
    fp();
}


int main()
{
    setlocale(LC_ALL, "Russian");
        
    //прямоугольный треугольник
    double a1 = 10, b1 = 20, c1 = 30;    
    double A1 = 50, B1 = 60, C1 = 70;
    std::string name1 = "Прямоугольный треугольник";
    if (C1 == 90)
    {
        Right_Triangle t1(name1, a1, b1, c1, A1, B1, C1);
        print_info(t1.get_triangle())
    }
    else
    {
        std::cout << "введите угол С равным 90 градусов" << std::endl;
    }
    
    //Равносторонний треугольник
    double a2 = 30, b2 = 20, c2 = 30;
    double A2 = 50, B2 = 60, C2 = 70;
    std::string name2 = "Равносторонний треугольник";
    if ((A2 == B2 == C2 == 60) && (a2 == b2 == c2))
    {
        Equilateral_Triangle t2(name2, a2, A2);
    }
    else
    {
        std::cout << "стороны должны быть равны и углы должны быть равны 60 градусов" << std::endl;
    }

    //Равнобедренный треугольник
    double a3 = 30, b3 = 20, c3 = 30;
    double A3 = 50, B3 = 60, C3 = 70;
    std::string name3 = "Равнобедренный треугольник";
    if ((A3 == C3) && (a3 == c3))
    {
        Isosceles_Triangle t3(name3, a3, b3, A3, B3);
    }
    else
    {
        std::cout << "стороны а и с должны быть равны и углы А и С должны быть равны" << std::endl;
    }

    //Квадрат
    double a4 = 30, b4 = 20, c4 = 30, d4 = 40;
    double A4 = 50, B4 = 60, C4 = 70, D4 = 10;
    std::string name4 = "Квадрат";
    if ((A4 == C4 == B4 == D4) && (a4 == c4 == b4 == d4))
    {
        Square t4(name4, a4, A4);
    }
    else
    {
        std::cout << "стороны должны быть равны и углы должны быть равны 90 градусов" << std::endl;
    }

    //параллелограмм
    double a5 = 30, b5 = 20, c5 = 30, d5 = 40;
    double A5 = 50, B5 = 60, C5 = 70, D5 = 10;
    std::string name5 = "Параллелограмм";
    if ((A5 == C5) && (B5 == D5) && (a5 == c5) && (b5 == d5))
    {
        Parallelogram t5(name5, a4, b4, A4, B4);
    }
    else
    {
        std::cout << "стороны должны быть равны и углы должны быть равны 90 градусов" << std::endl;
    }

    //Ромб
    double a6 = 30, b6 = 20, c6 = 30, d6 = 40;
    double A6 = 50, B6 = 60, C6 = 70, D6 = 10;
    std::string name6 = "Ромб";
    if ((A6 == C6) && (B6 == D6) && (a6 == c6 == b6 == d6))
    {
        Square t6(name6, a4, A4);
    }
    else
    {
        std::cout << "стороны должны быть равны и углы попарно должны быть равны" << std::endl;
    }
    
}