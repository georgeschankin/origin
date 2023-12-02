#include "Camel_Speed.h"

double rest(double S, double V, double t)
{
	int value; //счетчик количества отдыхов
	double time = 0; //количество часов отдыхов
	value = (S / V) / t;

	for (int i = 0; i < value; i++)
	{
		if (i == 0)
		{
			time += 5;
		}
		else if (i == 1)		
		{
			time += 6.5;
		}
		else
		{
			time += 8;
		}
	}
	return time;
}