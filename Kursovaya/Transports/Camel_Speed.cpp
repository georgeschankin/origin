#include "Camel_Speed.h"

double rest(double S, double V, double t)
{
	int value; //������� ���������� �������
	double time = 0; //���������� ����� �������
	value = (S / V) / t;

	for (int i = 0; i < value; i++)
	{
		if (i == 0)
		{
			time += 5;
		}
		else if (i == 1)		
		{
			time += 6.5;
		}
		else
		{
			time += 8;
		}
	}
	return time;
}