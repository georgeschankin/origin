#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSLAND_API __declspec(dllexport)
#else
#define TRANSPORTSLANDAPI __declspec(dllimport)
#endif

class Land_Transport
{
	TRANSPORTSLAND_API virtual double rest(double t);
};

