#include "Plane.h"

double short_distance(double S)
{
	if (S < 1000)
	{
		return 0;
	}
	else if ((S >= 1000) && (S < 5000))
	{
		return 3;
	}
	else if ((S >= 5000) && (S < 10000))
	{
		return 10;
	}
	else
	{
		return 5;
	}
}
