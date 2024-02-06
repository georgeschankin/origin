// my_first_cmake_project.cpp: определяет точку входа для приложения.
//

#include "my_first_cmake_project.h"
#include <windows.h>
#include <string>

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::string name;

	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Здравствуйте, " << name << "!" << std::endl;
	return 0;
}
