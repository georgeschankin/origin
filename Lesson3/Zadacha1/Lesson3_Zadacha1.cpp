
#include <iostream>

class Calculator
{
private:
    double _num1, _num2;
    
public:

    Calculator(double num1, double num2)
    {
        this->_num1 = num1;
        this->_num2 = num2;
    }

    
    double add()
    {      
        return _num1 + _num2;
    }

    double multiply()
    {       
        return _num1 * _num2;
    }

    double subtract_1_2()
    {       
        return _num1 - _num2;
    }

    double subtract_2_1()
    {       
        return _num2 - _num1;
    }

    double divide_2_1()
    {       
        return _num2 / _num1;
    }

    double divide_1_2()
    {       
        return _num1 / _num2;
    }

    bool set_num1()
    {
        if (_num1 != 0)
        {           
            return true;
        }
        else
        {
            return false;
        }
    }

    bool set_num2()
    {
        if (_num2 != 0)
        {            
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    double num1_, num2_;

    do
    {
        std::cout << "Введите num1 ";
        std::cin >> num1_;
        std::cout << "Введите num2 ";
        std::cin >> num2_;

        Calculator calc(num1_, num2_);

        if ((calc.set_num1() == false) || (calc.set_num2() == false))
        {
            std::cout << "неверный ввод!" << std::endl;           
        }
        else
        {
            std::cout << "num1 + num2 = " << calc.add() << std::endl;
            std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
            std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
            std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
            std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
            std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
            std::cout << "set_num1 = " << calc.set_num1() << std::endl;
            std::cout << "set_num2 = " << calc.set_num2() << std::endl;
        }

    } while (true);
}