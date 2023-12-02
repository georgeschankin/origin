#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSCAMEL_API __declspec(dllexport)
#else
#define TRANSPORTSCAMEL_API __declspec(dllimport)
#endif

#include "Land_Transport.h"
class Camel : public Land_Transport
{
public:
    TRANSPORTSCAMEL_API static double rest(double S, double V, double t);
};