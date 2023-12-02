#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSLAND_API __declspec(dllexport)
#else
#define TRANSPORTSLAND_API __declspec(dllimport)
#endif

class Land_Transport
{
public:
	TRANSPORTSLAND_API virtual double rest(double S, double V, double t);
};

