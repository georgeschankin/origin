
#include <iostream>

class Figure
{
private:
    int _side;
    std::string _name;

public:
    int get_sides_count()
    {
       return _side;
    }

    std::string get_name()
    {
       return _name;
    }

    Figure (int side, std::string name)
    {
        this->_side = side;
        this->_name = name;
    }

    Figure()
    {}
};

class Triangle: public Figure
{
public:
    Triangle() : Figure(3, "треугольник")
    {
        
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle() : Figure(4, "четырехугольник")
    {
        
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int side_triangle = 3;
    int side_quadrangle = 4;
    std::string name_triangle = "треугольник";
    std::string name_quadrangle = "четырехугольник";

    Triangle t;
    std::cout << t.get_sides_count() << std::endl;
    std::cout << t.get_name() << std::endl;

    Quadrangle q;
    std::cout << q.get_sides_count() << std::endl;
    std::cout << q.get_name() << std::endl;
}


