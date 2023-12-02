#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSCAMELSPEED_API __declspec(dllexport)
#else
#define TRANSPORTSCAMELSPEED_API __declspec(dllimport)
#endif

#include "Land_Transport.h"
class Camel_Speed : public Land_Transport
{
public:
    TRANSPORTSCAMELSPEED_API static double rest(double S, double V, double t);
};

