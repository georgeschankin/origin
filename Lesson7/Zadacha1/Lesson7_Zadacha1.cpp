
#include <iostream>

#define MODE 4 //объявил константу

int add(int a, int b)
{
	return a + b;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;

#ifndef MODE //проверил определена ли константа
#error необходимо определить MODE	
#elif MODE == 0 //проверка на нулевое значение
	std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1 //проверка на единичное значение
	std::cout << "работаю в боевом режиме" << std::endl;
	std::cout << "Введите число 1: " << std::endl;
	std::cin >> a;
	std::cout << "Введите число 2: " << std::endl;
	std::cin >> b;
	std::cout << "Результат сложения: " << add(a, b) << std::endl;
#else //любое другое значение
	std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif 
}
