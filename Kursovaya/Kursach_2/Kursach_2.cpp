#include <iostream>
#include ""

int main()
{
    //скорость
    const double V_Camel = 10; //верблюд    
    const double V_Camel_Speed = 40; //верблюд-быстроход
    const double V_Centaur = 15; //кентавр
    const double V_Boots = 6; //ботинки-вездеходы

    const double V_Plane = 10; //ковер-самолет
    const double V_Eagle = 8; //орел
    const double V_Broomstick = 20; //метла

    //время движения до отдыха
    const double t1_Camel = 30; //верблюд    
    const double t1_Camel_Speed = 10; //верблюд-быстроход
    const double t1_Centaur = 8; //кентавр
    const double t1_Boots = 60; //ботинки-вездеходы

    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
    std::cout << "1. Гонка для наземного транспорта" << std::endl;
    std::cout << "2. Гонка для воздушного транспорта" << std::endl;
    std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;

    int type; //тип гонки
    std::cout << "Введите тип гонки ";
    std::cin >> type;

    double S;  
    std::cout << "Укажите длину дистанции (должна быть положительной) ";
    std::cin >> S;

}


