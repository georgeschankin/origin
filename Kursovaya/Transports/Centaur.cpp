#include "Centaur.h"
#include <math.h>

double Centaur::rest(/*double S, double V, double t*/)
{
	int value; //счетчик количества отдыхов
	double time = 0; //количество часов отдыхов
	value = floor((S_ / V_) / t_);

	for (int i = 0; i < value; i++)
	{
		time += 2;
	}
	return time;
}
