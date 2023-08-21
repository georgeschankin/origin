
#include <iostream>

class Figure
{
private:
    int _side;
    std::string _name;
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

    Figure (int side, std::string name)
    {
        this->_side = side;
        this->_name = name;
    }

    Figure ()
    {}
};

class Triangle: public Figure
{
public:
    Triangle(int side, std::string name)
    {
        get_sides_count(side);
        get_name(name);
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle (int side, std::string name)
    {
        get_sides_count(side);
        get_name(name);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int side_triangle = 3;
    int side_quadrangle = 4;
    std::string name_triangle = "треугольник";
    std::string name_quadrangle = "четырехугольник";

    Triangle t(side_triangle, name_triangle);
    std::cout << t.get_sides_count(side_triangle) << std::endl;
    std::cout << t.get_name(name_triangle) << std::endl;

    Quadrangle q(side_quadrangle, name_quadrangle);
    std::cout << q.get_sides_count(side_quadrangle) << std::endl;
    std::cout << q.get_name(name_quadrangle) << std::endl;
}


