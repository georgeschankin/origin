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
    double S_, V_, t_;

    Camel_Speed(double S, double V, double t)
    {
        this->S_ = S;
        this->V_ = V;
        this->t_ = t;
    }

    TRANSPORTSCAMELSPEED_API double rest(/*double S, double V, double t*/);
};

