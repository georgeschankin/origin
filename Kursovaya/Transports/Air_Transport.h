#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSAIR_API __declspec(dllexport)
#else
#define TRANSPORTSAIR_API __declspec(dllimport)
#endif

class Air_Transport
{
public:
	TRANSPORTSAIR_API virtual double short_distance(double S);
};

