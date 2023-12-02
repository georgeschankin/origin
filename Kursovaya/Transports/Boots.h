#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSBOOTS_API __declspec(dllexport)
#else
#define TRANSPORTSBOOTS_API __declspec(dllimport)
#endif

#include "Land_Transport.h"
class Boots : public Land_Transport
{
public:
    TRANSPORTSBOOTS_API static double rest(double S, double V, double t);
};

