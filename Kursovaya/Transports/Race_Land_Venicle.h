#pragma once
#ifdef RACE_EXPORTS
#define RACELAND_API __declspec(dllexport)
#else
#define RACELAND_API __declspec(dllimport)
#endif

class Race_Land_Venicle
{
public:
	
	RACELAND_API static double final_land_distance(double S, double V, double t1); //итоговое время

	//S - дистанция, V - скорость, t2 - длительность отдыха
};