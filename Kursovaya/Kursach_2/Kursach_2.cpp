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
#include "Race_Air_Land_Venicle.h"
#include "Race_Air_Venicle.h"
#include "Race_Land_Venicle.h"
#include <math.h>
#include <Windows.h>

double sort(double *mass, int n)
{
    /* Отсортируем массив по убыванию */
    for (int i = 0; i < n; ++i)
    {
        for (int r = 0; r < n - i - 1; r++)
        {
            if (mass[r] < mass[r + 1])
            {
                // Обмен местами
                double temp = mass[r];
                mass[r] = mass[r + 1];
                mass[r + 1] = temp;
            }
        }
    }
    return *mass;
}

std::string sort_str(std::string* mass, int n)
{
    /* Отсортируем массив по убыванию */
    for (int i = 0; i < n; ++i)
    {
        for (int r = 0; r < n - i - 1; r++)
        {
            if (mass[r] < mass[r + 1])
            {
                // Обмен местами
                std::string temp = mass[r];
                mass[r] = mass[r + 1];
                mass[r + 1] = temp;
            }
        }
    }
    return *mass;
}

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

    double S = 0;//дистанция

    //регистрация транспорта
    int type_trans = 1; //вид  транспорта
    int reg = 1; //регистрация или начать гонку

    int exit = 1; //повтор или выход

    do
    {
        std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
        std::cout << "1. Гонка для наземного транспорта" << std::endl;
        std::cout << "2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;

        int type_race = 0; //тип гонки, 1 - наземная, 2 - воздушная, 3 - оба вида
        
        do
        {
            std::cout << "Введите тип гонки" << std::endl;
            std::cin >> type_race;
            if ((type_race >= 1) && (type_race <= 3)) { break; }
            else 
            { 
                std::cout << "Тип гонки может быть в пределах от 1 до 3. Введите правильный тип" << std::endl;
                continue; 
            }
        } while ((type_race < 1) || (type_race > 3));

        std::cout << "Укажите длину дистанции (должна быть положительной) ";
        do
        {
            std::cout << "Укажите длину дистанции (должна быть положительной) ";
            std::cin >> S;
            if (S > 0) { break; }
            else 
            { 
               std::cout << "Длина должна быть положительной";
               continue; 
            }
        } while (S <= 0);

        int N;

        do
        {          
            do
            {
                std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства. Введите количество желаемых зарегистрировать транспортных средств" << std::endl;
                std::cin >> N;
                if (N >= 2) { break; }
                else
                {
                    std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства";
                    continue;
                }
            } while (N < 2);

            std::cout << "1. Зарегистрировать транспорт " << std::endl;
            std::cin >> reg;

            double* trans = new double[N];          
            
            std::string* trans_name = new std::string[N];
            
            for (int i = 0; i < N; i++)
            {
                if ((type_race == 1) && (reg == 1))
                {
                    std::cout << "Гонка для наземного транспорта. Расстояние = ";
                    std::cout << S << std::endl;
                    std::cout << "1. Верблюд" << std::endl;
                    std::cout << "2. Верблюд-быстроход" << std::endl;
                    std::cout << "3. Кентавр" << std::endl;
                    std::cout << "4. Ботинки-вездеходы" << std::endl;
                    std::cout << "0. Закончить регистрацию" << std::endl;
                    std::cin >> type_trans;

                    if (type_trans == 1)
                    {
                        trans[i] = Race_Land_Venicle::final_land_distance(S, V_Camel, Camel::rest(S, V_Camel, t1_Camel));
                        trans_name[i] = "Верблюд";
                    }
                    else if (type_trans == 2)
                    {
                        trans[i] = Race_Land_Venicle::final_land_distance(S, V_Camel_Speed, Camel_Speed::rest(S, V_Camel_Speed, t1_Camel_Speed));
                        trans_name[i] = "Верблюд-быстроход";
                    }
                    else if (type_trans == 3)
                    {
                        trans[i] = Race_Land_Venicle::final_land_distance(S, V_Centaur, Centaur::rest(S, V_Centaur, t1_Centaur));
                        trans_name[i] = "Кентавр";
                    }
                    else if (type_trans == 4)
                    {
                        trans[i] = Race_Land_Venicle::final_land_distance(S, V_Boots, Boots::rest(S, V_Boots, t1_Boots));
                        trans_name[i] = "Ботинки-вездеходы";
                    }
                    else
                    {
                        std::cout << "1. Зарегистрировать транспорт " << std::endl;
                        std::cout << "2. Начать гонку " << std::endl;
                        std::cin >> reg;
                        if (reg == 1)
                        {
                            i++;
                            continue;
                        }
                        else
                        {
                            std::cout << sort(trans, N);
                            std::cout << sort_str(trans_name, N);
                            std::cout << "Последний победил" << std::endl;
                            //delete[] trans, trans_name;
                            break;
                        }
                    }
                }
                else if ((type_race == 2) && (reg == 1))
                {
                    std::cout << "Гонка для воздушного транспорта. Расстояние = ";
                    std::cout << S << std::endl;
                    std::cout << "5. Ковёр-самолёт" << std::endl;
                    std::cout << "6. Орёл" << std::endl;
                    std::cout << "7. Метла" << std::endl;
                    std::cout << "0. Закончить регистрацию" << std::endl;
                    std::cin >> type_trans;

                    if (type_trans == 5)
                    {
                        trans[i] = Race_Air_Venicle::final_air_distance(S, V_Plane, Plane::short_distance(S));
                        trans_name[i] = "Ковёр-самолёт";
                    }
                    else if (type_trans == 6)
                    {
                        trans[i] = Race_Air_Venicle::final_air_distance(S, V_Eagle, Eagle::short_distance(S));
                        trans_name[i] = "Орёл";
                    }
                    else if (type_trans == 7)
                    {
                        trans[i] = Race_Air_Venicle::final_air_distance(S, V_Broomstick, Broomstick::short_distance(S));
                        trans_name[i] = "Метла";
                    }
                    else
                    {
                        std::cout << "1. Зарегистрировать транспорт " << std::endl;
                        std::cout << "2. Начать гонку " << std::endl;
                        std::cin >> reg;
                        if (reg == 1)
                        {
                            i++;
                            continue;
                        }
                        else
                        {
                            std::cout << sort(trans, N);
                            std::cout << sort_str(trans_name, N);
                            std::cout << "Последний победил" << std::endl;
                            //delete[] trans, trans_name;
                            break;
                        }
                    }
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
                    std::cin >> type_trans;

                    if (type_trans == 1)
                    {
                        //trans3[i] = Race_Air_Land_Venicle::final_air_land_distance(S, V_Camel, Camel::rest(S, V_Camel, t1_Camel), 0.0, 1);
                        trans[i] = Race_Land_Venicle::final_land_distance(S, V_Camel, Camel::rest(S, V_Camel, t1_Camel));
                        trans_name[i] = "Верблюд";
                    }
                    else if (type_trans == 2)
                    {
                        trans[i] = Race_Land_Venicle::final_land_distance(S, V_Camel_Speed, Camel_Speed::rest(S, V_Camel_Speed, t1_Camel_Speed));
                        trans_name[i] = "Верблюд-быстроход";
                    }
                    else if (type_trans == 3)
                    {
                        trans[i] = Race_Land_Venicle::final_land_distance(S, V_Centaur, Centaur::rest(S, V_Centaur, t1_Centaur));
                        trans_name[i] = "Кентавр";
                    }
                    else if (type_trans == 4)
                    {
                        trans[i] = Race_Land_Venicle::final_land_distance(S, V_Boots, Boots::rest(S, V_Boots, t1_Boots));
                        trans_name[i] = "Ботинки-вездеходы";
                    }
                    if (type_trans == 5)
                    {
                        trans[i] = Race_Air_Venicle::final_air_distance(S, V_Plane, Plane::short_distance(S));
                        trans_name[i] = "Ковёр-самолёт";
                    }
                    else if (type_trans == 6)
                    {
                        trans[i] = Race_Air_Venicle::final_air_distance(S, V_Eagle, Eagle::short_distance(S));
                        trans_name[i] = "Орёл";
                    }
                    else if (type_trans == 7)
                    {
                        trans[i] = Race_Air_Venicle::final_air_distance(S, V_Broomstick, Broomstick::short_distance(S));
                        trans_name[i] = "Метла";
                    }
                    else
                    {
                        std::cout << "1. Зарегистрировать транспорт " << std::endl;
                        std::cout << "2. Начать гонку " << std::endl;
                        std::cin >> reg;
                        if (reg == 1)
                        {
                            i++;
                            continue;
                        }
                        else
                        {
                            std::cout << sort(trans, N);
                            std::cout << sort_str(trans_name, N);
                            std::cout << "Последний победил" << std::endl;
                            //delete[] trans, trans_name;
                            break;
                        }
                    }                   
                }
            }
            delete[] trans, trans_name;
        }while (reg == 1);
        
        std::cout << "повторить гонку или стоп (1 - повтор, любое другое число - стоп) ";
        std::cin >> exit;
        if (exit == 1) { continue; }
        else { break; }
    } while (exit == 1);
    
    return 0;
}


