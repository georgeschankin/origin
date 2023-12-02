#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSCENTAUR_API __declspec(dllexport)
#else
#define TRANSPORTSCENTAUR_API __declspec(dllimport)
#endif

#include "Land_Transport.h"
class Centaur : public Land_Transport
{
public:
    TRANSPORTSCENTAUR_API static double rest(double S, double V, double t);
};

