#include <iostream>

/*class Figure
{
private:
    int _side; //количество сторон
    std::string _name; //название
    int sides_count(int _side)
    {
        return _side;
    }

    std::string names_count(std::string _name)
    {
        return _name;
    }

public:
    int get_sides_count(int side)
    {
        return sides_count(side);
    }

    std::string get_name(std::string name)
    {
        return names_count(name);
    }

    Figure(int side, std::string name)
    {
        this->_side = side;
        this->_name = name;
    }

    Figure()
    {}
};*/

class Triangle /*: public Figure*/
{
private:
    double a, b, c; //стороны
    double A, B, C; //углы
    std::string _name; //название

public:
    
    Triangle(std::string name, double a, double b, double c, double A, double B, double C)
    {
        this->_name = name;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    void get_sides_count()
    {
        std::cout << _name << std::endl;
        std::cout << "Стороны: a=" << a << " b = " << b << " c = " << c << std::endl;
        std::cout << "Углы: А=" << A << " В = " << B << " С = " << C << std::endl;
    }

};

class Right_Triangle : public Triangle
{
public:
    double a = 10, b = 20, c = 30; //стороны
    double A = 50, B = 60, C = 70; //углы
    std::string name = "Прямоугольный треугольник"; //название

    Triangle(name, a, b, c, A, B, C;)
    {
        get_sides_count();
    }
};

class Isosceles_Triangle : public Triangle
{
public:
    double a = 10, b = 20, c = 10; //стороны
    double A = 50, B = 60, C = 70; //углы
    std::string name = "Равнобедренный треугольник"; //название

    Triangle(name, a, b, c, A, B, C)
    {
        get_sides_count();
    }
};

class Quadrangle : public Figure
{
public:
    double a, b, c, d; //стороны
    double A, B, C, D; //углы
    Quadrangle(int side, std::string name)
    {
        get_sides_count(side);
        get_name(name);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int side_triangle = 3;    
    double a1 = 10, b1 = 20, c1 = 30;    
    double A1 = 50, B1 = 60, C1 = 70;
    std::string name_triangle = "треугольник";    
    Triangle t(side_triangle, name_triangle);
    std::cout << t.get_sides_count(side_triangle) << std::endl;
    std::cout << t.get_name(name_triangle) << std::endl;


    int side_quadrangle = 4;
    double a2 = 10, b2 = 20, c2 = 30, d2 = 40;
    double A2 = 50, B2 = 60, C2 = 70, D2 = 80;
    std::string name_quadrangle = "четырехугольник";

    Quadrangle q(side_quadrangle, name_quadrangle);
    std::cout << q.get_sides_count(side_quadrangle) << std::endl;
    std::cout << q.get_name(name_quadrangle) << std::endl;
}