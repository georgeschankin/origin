#include "Boots.h"
#include <math.h>

double Boots::rest(/*double S, double V, double t*/)
{
	int value; //������� ���������� �������
	double time = 0; //���������� ����� �������
	value = floor((S_ / V_) / t_);

	for (int i = 0; i < value; i++)
	{
		if (i == 0)
		{
			time += 10;
		}
		else
		{
			time += 5;
		}
	}
	return time;
}