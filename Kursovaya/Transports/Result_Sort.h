#include <string>

#pragma once
#ifdef TRANSPORTS_EXPORTS
#define SORT_API __declspec(dllexport)
#else
#define SORT_API __declspec(dllimport)
#endif

class Result_Sort
{
public:
	double time_;
	std::string name_trans_;	

	Result_Sort(double time, std::string name_trans)
	{
		this->time_ = time;
		this->name_trans_ = name_trans;
	}

	Result_Sort() {}

	SORT_API static void sort(Result_Sort* res, int size);
};

