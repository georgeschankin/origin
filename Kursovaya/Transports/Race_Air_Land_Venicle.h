#pragma once
#ifdef RACE_EXPORTS
#define RACEAIRLAND_API __declspec(dllexport)
#else
#define RACEAIRLAND_API __declspec(dllimport)
#endif

class Race_Air_Land_Venicle
{
public:

	RACEAIRLAND_API double final_air_land_distance(double S, double V, double t2, double k, int type); //�������� �����

	//S - ���������, V - ��������, k - ����������� ���������� ����������, t2 - ������������ ������, type - ��� ����������
};