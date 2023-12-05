#include "Broomstick.h"
#include <math.h>

double Broomstick::short_distance(/*double S*/)
{
	if (S_ < 1000)
	{
		return 0;
	}
	else
	{
       return floor(S_ / 1000);
	}	
}