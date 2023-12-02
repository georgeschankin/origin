#include "Race_Air_Venicle.h"

double Race_Air_Venicle::final_air_distance(double S, double V, double k)
{
	return ((S * (1 - (k/100))) / V);
}