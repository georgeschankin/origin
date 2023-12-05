#include "Plane.h"

double Plane::short_distance(/*double S*/)
{
	if (S_ < 1000)
	{
		return 0;
	}
	else if ((S_ >= 1000) && (S_ < 5000))
	{
		return 3;
	}
	else if ((S_ >= 5000) && (S_ < 10000))
	{
		return 10;
	}
	else
	{
		return 5;
	}
}
