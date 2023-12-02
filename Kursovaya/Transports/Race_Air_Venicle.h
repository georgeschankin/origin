#pragma once
#ifdef RACE_EXPORTS
#define RACEAIR_API __declspec(dllexport)
#else
#define RACEAIR_API __declspec(dllimport)
#endif

class Race_Air_Venicle
{
public:

	RACEAIR_API static double final_air_distance(double S, double V, double k); //итоговое время

	//S - дистанция, V - скорость, k - коэффициент сокращения расстояния
};