#include "functions.h"

int plus(int a, int b)
{
	return a + b;
}

int minus(int a, int b)
{
	return a - b;
}

int multiplication(int a, int b)
{
	return a * b;
}

int division(int a, int b)
{
	return a / b;
}

int exp(int a, int b)
{
	int a1 = 1;
	for (int i = 0; i < b; i++)
	{
		a1 = a1 * a;
	}
	return a1;
}