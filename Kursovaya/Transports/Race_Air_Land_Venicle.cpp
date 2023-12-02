#include "Race_Air_Land_Venicle.h"
#include "Race_Air_Venicle.h"
#include "Race_Land_Venicle.h"

double Race_Air_Land_Venicle::final_air_land_distance(double S, double V, double t2, double k, int type)
{
	//наземный
	if (type == 1)
	{
		//return S / V + t2;
		return Race_Land_Venicle::final_land_distance(S, V, t2);
	}
	//воздушный
	else if (type == 2)
	{
		//return ((S * (1 - (k / 100))) / V);
		return Race_Air_Venicle::final_air_distance(S, V, k);
	}
}