#include "Camel_Speed.h"

double rest(double t, int i)
{
	//i - счетчик отдыхов

	if (i == 1)
	{
		return 5;
	}
	else if(i == 2)
	{
		return 6.5;
	}
	else
	{
		return 8;
	}
}