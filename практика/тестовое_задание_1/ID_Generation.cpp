#include "ID_Generation.h"

std::string ID_Generation::GenID_A1_to_Z9(std::string identifier)
{
	if (identifier == "Z9") return "A1-A1"; //проверка на последний элемент
	else
	{
		for (int i = 0; i < SIZENUM; i++) //проверяем цифры
		{	
			//если цифра равна 9, то меняем на следующую букву + 1
			if ((identifier.find(std::to_string(this->Numbers[SIZENUM - 1])) != std::string::npos) && (identifier[0] != 'Z')) 			
			{
				for (int j = 0; j < SIZE; j++) //проверяем буквы
				{
					if (identifier.find(this->ValueIndeff[j]) != std::string::npos)
					{ 
						std::string s(1, ValueIndeff[j + 1]);
						return s + "1"; 
					}
				}										
			}
			else if (identifier.find(std::to_string(this->Numbers[i])) != std::string::npos) //если другая цифра, то прибавляем ее
			{ return identifier.replace(1, 1, std::to_string(this->Numbers[i + 1])); }
			else if (identifier[0] == 'D' ||
				identifier[0] == 'F' ||
				identifier[0] == 'G' ||
				identifier[0] == 'J' ||
				identifier[0] == 'M' ||
				identifier[0] == 'Q' ||
				identifier[0] == 'V' ||
				identifier[1] == '0') throw std::out_of_range("Нельзя использовать буквы «D», «F», «G», «J», «M», «Q», «V» и цифру «0»\n");
			else throw std::out_of_range("Некорректные данные\n");
		}
	}
}

std::string ID_Generation::GenID_A1_A1_to_Z9_Z9(std::string identifier)
{
	if(identifier == "Z9-Z9") throw std::out_of_range("Введен максимум\n");
	else if (identifier.find("-Z9") != std::string::npos) return this->GenID_A1_to_Z9(identifier.substr(0, 2)) + "-" + "A1";
	else return identifier.substr(0, 3) + this->GenID_A1_to_Z9(identifier.substr(3, 2));
}

std::string ID_Generation::GenerateNextIdentifier(const std::string& identifier)
{
	try
	{
		if (identifier.size() == 5) return this->GenID_A1_A1_to_Z9_Z9(identifier);
		else if (identifier.size() == 2) return this->GenID_A1_to_Z9(identifier);
		else throw std::out_of_range("Введены неправильные данные\n");
	}
	catch (const std::exception& e)
	{ return e.what(); }
	catch (...)
	{ return "неизвестная ошибка"; }		
}