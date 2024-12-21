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
	std::string getvaluestring(const std::string& section, const std::string& var)
	{
		//TODO: ����������� �� �����, ���� ��������
		return "1.3";
	}

public:
	Ini_Parser(std::string file_ )
	{
		this->file = file_;
	}

	//����� ����������� �������� � ���� int � double
	template<class T>
	T get_value(std::string section, std::string number)
	{
		;
		static_assert(sizeof(T) == -1, "�� ������������� ��� ��� get_value");
	}

	// ����� ������������ �������� � ���� string
	template<>
	std::string get_value(std::string section, std::string var)
	{
		read();

		std::string res = "";

		for (auto it = section_name_value.begin(); it != section_name_value.end(); ++it)
		{
			if (it->first == section)
			{
				if (it->second.first == var)
				{
					res = it->second.second;
				}
			}
		}
		return res;
	}

	// ����� ������������ �������� � ���� int 
	template<>
	int get_value(std::string section, std::string var)
	{
		read();
		//TODO: ������� ������� � int
		return 0;
	}
};

