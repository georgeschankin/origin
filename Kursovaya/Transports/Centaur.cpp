#include "Centaur.h"

double rest(double S, double V, double t)
{
	int value; //������� ���������� �������
	double time = 0; //���������� ����� �������
	value = (S / V) / t;

	for (int i = 0; i < value; i++)
	{
		time += 2;
	}
	return time;
}
