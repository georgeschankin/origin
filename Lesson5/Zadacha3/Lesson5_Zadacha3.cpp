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
        if ((side == 3) && ((A + B + C) == 180.0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print_info()
    {       
        Figure::print_info(); 
        std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << std::endl;
        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;
    }    
};

class Right_Triangle : public Triangle
{
public:    
    double C; //углы

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

    void print_info()
    {               
        Triangle::print_info();       
    }   
};

class Isosceles_Triangle : public Triangle
{
public:    
    double a, c; //стороны
    double A, C; //углы

    Isosceles_Triangle(std::string name, int side, double a, double b, double c, double A, double B, double C) : Triangle(name, side, a, b, c, A, B, C)
    {       
        this->a = a;       
        this->c = c;
        this->A = A;       
        this->C = C;
    }

    bool check()
    {
        if ((a == c) && (A == C))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print_info()
    {
        Triangle::print_info();
    }      
};

class Equilateral_Triangle : public Triangle
{
public:   
    double a, b, c; //стороны
    double A, B, C; //углы

    Equilateral_Triangle(std::string name, int side, double a, double b, double c, double A, double B, double C) : Triangle(name, side, a, b, c, A, B, C)
    {       
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    bool check()
    {
        if ((A == 60) && (B == 60) && (C == 60) && (a == b) && (b == c) && (a == c))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print_info()
    {
        Triangle::print_info();
    }    
};

class Quadrangle : public Figure
{
private:
    std::string _name; //название
    double a, b, c, d; //стороны
    int side; //количество сторон        
    double A, B, C, D; //углы

public:

    Quadrangle(std::string name, int side, double a, double b, double c, double d, double A, double B, double C, double D) : Figure(name, side)
    {       
        this->side = side; 
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    bool check()
    {
        if ((side == 4) && ((A + B + C + D) == 360.0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print_info()
    {
        Figure::print_info();
        std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << " " << "d = " << d << std::endl;
        std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << " " << "D = " << D << std::endl;
    }
};

class Rectangle : public Quadrangle
{
public:   
    double a, b, c, d; //стороны
    double A, B, C, D; //углы

    Rectangle(std::string name, int side, double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(name, side, a, b, c, d, A, B, C, D)
    {       
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    bool check()
    {
        if ((a == c) && (b == d) && (A == 90) && (B == 90) && (C == 90) && (D == 90))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print_info()
    {
        Quadrangle::print_info();
    }
};

class Square : public Quadrangle
{
public:    
    double a, b, c, d; //стороны
    double A, B, C, D; //углы

    Square(std::string name, int side, double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(name, side, a, b, c, d, A, B, C, D)
    {       
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    bool check()
    {
        if ((a == b) && (b == c) && (c == d) && (a == d) && (A == 90) && (B == 90) && (C == 90) && (D == 90))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print_info()
    {
        Quadrangle::print_info();
    }
};

class Parallelogram : public Quadrangle
{
public:    
    double a, b, c, d; //стороны
    double A, B, C, D; //углы

    Parallelogram(std::string name, int side, double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(name, side, a, b, c, d, A, B, C, D)
    {        
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    bool check()
    {
        if ((a == c) && (b == d) && (A == C) && (B == D))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print_info()
    {
        Quadrangle::print_info();
    }
};

class Romb : public Quadrangle
{
public:    
    double a, b, c, d; //стороны
    double A, B, C, D; //углы

    Romb(std::string name, int side, double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(name, side, a, b, c, d, A, B, C, D)
    {       
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    bool check()
    {
        if ((a == b) && (b == c) && (c == d) && (a == d) && (A == C) && (B == D))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print_info()
    {
        Quadrangle::print_info();
    }
};


/*void print_info(Figure* figure)
{
    figure->print_info();
}*/


int main()
{
    setlocale(LC_ALL, "Russian");

    int side_triangle = 3, side_quarangle = 4;

    //прямоугольный треугольник
    double a1 = 10, b1 = 20, c1 = 30;
    double A1 = 50, B1 = 60, C1 = 90;
    std::string name1 = "Прямоугольный треугольник";
            
        Right_Triangle t1(name1, side_triangle, a1, b1, c1, A1, B1, C1);        
        t1.print_info();        
 
    std::cout << "\n";

    //Равносторонний треугольник
    double a2 = 30, b2 = 30, c2 = 30;
    double A2 = 60, B2 = 60, C2 = 60;
    std::string name2 = "Равносторонний треугольник";
            
        Equilateral_Triangle t2(name2, side_triangle, a2, b2, c2, A2, B2, C2);        
        t2.print_info();
    
    std::cout << "\n";

    //Равнобедренный треугольник
    double a3 = 30, b3 = 20, c3 = 30;
    double A3 = 70, B3 = 60, C3 = 70;
    std::string name3 = "Равнобедренный треугольник";
           
        Isosceles_Triangle t3(name3, side_triangle, a3, b3, c3, A3, B3, C3);        
        t3.print_info();
    
    std::cout << "\n";

    //Квадрат
    double a4 = 30, b4 = 30, c4 = 30, d4 = 30;
    double A4 = 90, B4 = 90, C4 = 90, D4 = 90;
    std::string name4 = "Квадрат";
           
        Square t4(name4, side_quarangle, a4, b4, c4, d4, A4, B4, C4, D4);
        t4.print_info();
    
    std::cout << "\n";

    //параллелограмм
    double a5 = 30, b5 = 20, c5 = 30, d5 = 20;
    double A5 = 50, B5 = 60, C5 = 50, D5 = 60;
    std::string name5 = "Параллелограмм";
           
        Parallelogram t5(name5, side_quarangle, a5, b5, c5, d5, A5, B5, C5, D5);
        t5.print_info();
    
    std::cout << "\n";

    //Ромб
    double a6 = 30, b6 = 30, c6 = 30, d6 = 30;
    double A6 = 70, B6 = 50, C6 = 70, D6 = 50;
    std::string name6 = "Ромб";
            
        Square t6(name6, side_quarangle, a6, b6, c6, d6, A6, B6, C6, D6);
        t6.print_info();

}
