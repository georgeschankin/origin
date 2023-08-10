
#include <iostream>

class Calculator
{
private:
    double _num1, _num2;
    
public:    
    
    double add(double num1, double num2)
    {
        this->_num1 = num1;
        this->_num2 = num2;
        return _num1 + _num2;
    }

    double multiply(double num1, double num2)
    {
        this->_num1 = num1;
        this->_num2 = num2;
        return _num1 * _num2;
    }

    double subtract_1_2(double num1, double num2)
    {
        this->_num1 = num1;
        this->_num2 = num2;
        return _num1 - _num2;
    }

    double subtract_2_1(double num1, double num2)
    {
        this->_num1 = num1;
        this->_num2 = num2;
        return _num2 - _num1;
    }

    double divide_2_1(double num1, double num2)
    {
        this->_num1 = num1;
        this->_num2 = num2;
        return _num2 / _num1;
    }

    double divide_1_2(double num1, double num2)
    {
        this->_num1 = num1;
        this->_num2 = num2;
        return _num1 / _num2;
    }

    bool set_num1(double num1)
    {
        if (num1 != 0)
        {
            this->_num1 = num1;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool set_num2(double num2)
    {
        if (num2 != 0)
        {
            this->_num2 = num2;
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

        Calculator calc;

        if ((calc.set_num1(num1_) == false) || (calc.set_num2(num2_) == false))
        {
            std::cout << "неверный ввод!" << std::endl;           
        }
        else
        {
            std::cout << "num1 + num2 = " << calc.add(num1_, num2_) << std::endl;
            std::cout << "num1 - num2 = " << calc.subtract_1_2(num1_, num2_) << std::endl;
            std::cout << "num2 - num1 = " << calc.subtract_2_1(num1_, num2_) << std::endl;
            std::cout << "num1 * num2 = " << calc.multiply(num1_, num2_) << std::endl;
            std::cout << "num1 / num2 = " << calc.divide_1_2(num1_, num2_) << std::endl;
            std::cout << "num2 / num1 = " << calc.divide_2_1(num1_, num2_) << std::endl;
            std::cout << "set_num1 = " << calc.set_num1(num1_) << std::endl;
            std::cout << "set_num2 = " << calc.set_num2(num2_) << std::endl;
        }

    } while (true);
}