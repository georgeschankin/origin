
#include <iostream>

class Calculator
{
/*private:
    double _num1, _num2; */
    
public:
    double _num1, _num2;

    Calculator()
    {        
        
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

    bool set_num1(double num1)
    {
        if (_num1 != 0)
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
        if (_num2 != 0)
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

    Calculator calc; //когда объявляю класс за пределами цикла, то программа работает некорректно

    do
    {
        std::cout << "Введите num1 ";
        std::cin >> num1_;
        std::cout << "Введите num2 ";
        std::cin >> num2_;

        //Calculator calc; //когда объявляю класс здесь, то программа работает корректно

        if ((calc.set_num1(num1_) == false) || (calc.set_num2(num2_) == false))
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
        }

    } while (true);
}