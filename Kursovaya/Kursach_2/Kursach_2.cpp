#include <iostream>
#include "Air_Transport.h"
#include "Boots.h"
#include "Broomstick.h"
#include "Camel.h"
#include "Camel_Speed.h"
#include "Centaur.h"
#include "Eagle.h"
#include "Land_Transport.h"
#include "Plane.h"
#include <math.h>
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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
    
    int exit = 1; //повтор или выход

    //do
    //{
    while (exit == 1)
    {
      int type_race; //тип гонки, 1 - наземная, 2 - воздушная, 3 - оба вида
      std::cout << "Введите тип гонки ";
      std::cin >> type_race;

        if ((type_race >= 1) && (type_race <= 3))
        {
            double S;//дистанция  
            std::cout << "Укажите длину дистанции (должна быть положительной) ";
            std::cin >> S;
    
            if (S > 0)
            {
            /*
                //регистрация транспорта
                //int type_land_trans; //вид наземного транспорта
                //int type_air_trans; //вид воздушного транспорта
                int type_trans; //вид  транспорта
                int reg; //регистрация или начать гонку
                int i = 0;

                std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
                while ((reg != 2) || (type_trans != 0))
                {
                    if (i < 2)
                    {
                        std::cout << "1. Зарегистрировать транспорт " << std::endl;
                        std::cin >> reg;
                    
                        if ((type_race == 1) && (reg == 1))
                        {
                            std::cout << "Гонка для наземного транспорта. Расстояние = ";
                            std::cout << S << std::endl;
                            std::cout << "1. Верблюд" << std::endl;
                            std::cout << "2. Верблюд-быстроход" << std::endl;
                            std::cout << "3. Кентавр" << std::endl;
                            std::cout << "4. Ботинки-вездеходы" << std::endl;
                            std::cout << "0. Закончить регистрацию" << std::endl;
                        }
                        else if ((type_race == 2) && (reg == 1))
                        {
                            std::cout << "Гонка для воздушного транспорта. Расстояние = ";
                            std::cout << S << std::endl;
                            std::cout << "5. Ковёр-самолёт" << std::endl;
                            std::cout << "6. Орёл" << std::endl;
                            std::cout << "7. Метла" << std::endl;
                            std::cout << "0. Закончить регистрацию" << std::endl;
                        }
                        else if ((type_race == 3) && (reg == 1))
                        {
                            std::cout << "Гонка для наземного и воздушного транспорта. Расстояние = ";
                            std::cout << S << std::endl;
                            std::cout << "1. Верблюд" << std::endl;
                            std::cout << "2. Верблюд-быстроход" << std::endl;
                            std::cout << "3. Кентавр" << std::endl;
                            std::cout << "4. Ботинки-вездеходы" << std::endl;
                            std::cout << "5. Ковёр-самолёт" << std::endl;
                            std::cout << "6. Орёл" << std::endl;
                            std::cout << "7. Метла" << std::endl;
                            std::cout << "0. Закончить регистрацию" << std::endl;
                        }       
                    
                    }
                    else
                    {
                        std::cout << "1. Зарегистрировать транспорт " << std::endl;
                        std::cout << "2. Начать гонку " << std::endl;
                        std::cin >> reg;
                    }
                    i++;
                }*/
       
                //доработать регистрацию нужного количество транспорта
                
            }
            else
            {
                do
                {
                    std::cout << "Введите положительное число" << std::endl;  
                    std::cin >> S;
                    //if (S > 0) { continue; }
                } while (S <= 0);
                /*std::cout << "Введите положительное число" << std::endl;
                std::cin >> S;
                continue;*/
            }
        }
        else
        {
            do
            {
                std::cout << "Введите правильный тип гонки" << std::endl;
                std::cin >> type_race;
                //if ((type_race >= 1) && (type_race <= 3)) { break; }
            } while ((type_race < 1) || (type_race > 3));

            /*std::cout << "Введите правильный тип гонки" << std::endl;
            std::cin >> type_race;
            continue;*/
        }
        std::cout << "повторить гонку или стоп" << std::endl;
        std::cin >> exit;
    }
        
    //} while (exit != 2);
    
    
    //system("pause");
    //return 0;
    
}


