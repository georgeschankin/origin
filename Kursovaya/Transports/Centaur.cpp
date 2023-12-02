#include "Centaur.h"

double rest(double S, double V, double t)
{
	int value; //счетчик количества отдыхов
	double time = 0; //количество часов отдыхов
	value = (S / V) / t;

	for (int i = 0; i < value; i++)
	{
		time += 2;
	}
	return time;
}
