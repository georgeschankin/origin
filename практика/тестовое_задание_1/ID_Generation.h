#pragma once

#include <iostream>
#include <string>

#define SIZE 19
#define SIZENUM 9

class ID_Generation
{
private:	
	char ValueIndeff[SIZE] = { 'A', 'B', 'C', 'E', 'H', 'I', 'K', 'L', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'W', 'X', 'Y', 'Z' };
	int Numbers[SIZENUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	/**
	 * @brief  Функция генерирует новый ID с A1 до Z9
	 * @param  ID
	 * @retval Новый ID
	*/
	std::string GenID_A1_to_Z9(std::string identifier);

	/**
	 * @brief  Функция генерирует новый ID с A1-A1 до  A1-Z9
	 * @param  ID
	 * @retval Новый ID
	*/
	std::string GenID_A1_A1_to_Z9_Z9(std::string identifier);

public:

	ID_Generation() = default;
	
	/**
	 * @brief  Функция генерирует новый ID на основе переданного
	 * @param  ID
	 * @retval Новый ID
	*/
	std::string GenerateNextIdentifier(const std::string& identifier);
};

