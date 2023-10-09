#include "Broomstick.h"
#include <math.h>

double short_distance(double S)
{
	if (S < 1000)
	{
		return 0;
	}
	else
	{
       return floor(S / 1000);
	}	
}