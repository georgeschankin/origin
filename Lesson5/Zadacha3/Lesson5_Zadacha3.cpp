#include <iostream>

class Figure
{
private:
    std::string name; //название
    int side; //количество сторон

public:

    Figure(std::string name, int side)
    {
        this->name = name;
        this->side = side;       
    }

    Figure()
    {}
   
    virtual bool check()
    {
        if (side == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    virtual void print_info()
    {
        std::cout << name << std::endl;

        if (check() == true)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
        
        std::cout << "Количество сторон: " << side << std::endl;
    }

};

class Triangle : public Figure
{
private:
    std::string _name; //название
    double a, b, c; //стороны
    double A, B, C; //углы
    int side; //количество сторон

public:

    Triangle(std::string name, int side, double a, double b, double c, double A, double B, double C) : Figure(name, side)
    {
        this->_name = name;
        this->side = side;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    bool check()
    {
        if ((side == 3) && ((A + B + C) == 180))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //здесь вопрос, как мне передать значение переопределенной функции check у каждого класса, если функцию print_info нужно наследовать из родительского класса
    void print_info()
    {
        return Figure::print_info();
        std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << std::endl;
        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;
    }


    /*void print_info() override
    {
        std::cout << _name << std::endl;
        if (check() == true)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << side << std::endl;
        std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << std::endl;
        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;
    }*/
};

class Right_Triangle : public Triangle
{
public:
    int side; //количество сторон
    std::string _name; //название
    double a, b, c; //стороны
    double A, B, C; //углы

    Right_Triangle(std::string name, int side, double a, double b, double c, double A, double B, double C) : Triangle(name, side, a, b, c, A, B, C)
    {
        this->C = C;
    }

    bool check()
    {
        if (C == 90)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print_info() override
    {
        std::cout << _name << std::endl;
        if (check() == true)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << side << std::endl;
        std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << std::endl;
        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;
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
private:
    std::string _name; //название
    double a, b, c, d; //стороны
    double A, B, C, D; //углы

public:

    Quadrangle(std::string name, double a, double b, double c, double d, double A, double B, double C, double D)
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

    void print_info() override
    {
        std::cout << _name << std::endl;
        std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << " " << "d = " << d << std::endl;
        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << " " << "D = " << D << std::endl;
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

    Parallelogram(std::string name, double a, double b, double A, double D) : Quadrangle(name, a, b, a, b, A, D, A, D)
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


void print_info(Figure* figure)
{
    figure->print_info();
}


int main()
{
    setlocale(LC_ALL, "Russian");

    //прямоугольный треугольник
    double a1 = 10, b1 = 20, c1 = 30;
    double A1 = 50, B1 = 60, C1 = 90;
    std::string name1 = "Прямоугольный треугольник";
    if (C1 == 90)
    {
        Figure* p1 = nullptr;
        Right_Triangle t1(name1, a1, b1, c1, A1, B1, C1);
        p1 = &t1;
        print_info(p1);
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
    if ((A2 == B2 == C2 == 60) && (a2 == b2 == c2))
    {
        Figure* p2 = nullptr;
        Equilateral_Triangle t2(name2, a2, A2);
        p2 = &t2;
        print_info(p2);
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
        Figure* p3 = nullptr;
        Isosceles_Triangle t3(name3, a3, b3, A3, B3);
        p3 = &t3;
        print_info(p3);
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
    if ((A4 == C4 == B4 == D4) && (a4 == c4 == b4 == d4))
    {
        Figure* p4 = nullptr;
        Square t4(name4, a4, A4);
        p4 = &t4;
        print_info(p4);
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
        Figure* p5 = nullptr;
        Parallelogram t5(name5, a4, b4, A4, B4);
        p5 = &t5;
        print_info(p5);
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
    if ((A6 == C6) && (B6 == D6) && (a6 == c6 == b6 == d6))
    {
        Figure* p6 = nullptr;
        Square t6(name6, a4, A4);
        p6 = &t6;
        print_info(p6);
    }
    else
    {
        std::cout << "стороны должны быть равны и углы попарно должны быть равны" << std::endl;
    }

}
