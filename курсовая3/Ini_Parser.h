#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

class Ini_Parser
{
private:
	std::string file, str;
	std::ifstream f_in;
	std::vector<std::string> section, val, nameval;
	std::multimap<std::string, std::pair<std::string, std::string>> section_name_value;	

	bool is_number(const std::string& s);
	void read();

public:
	Ini_Parser(std::string file_ )
	{
		this->file = file_;
	}

	//Метод возращающий значение в типе int и double
	template<class T>
	T get_value(std::string section, std::string number);

	// Метод возвращающее значение в типе string	
	std::string get_value(std::string section, std::string var);
};

