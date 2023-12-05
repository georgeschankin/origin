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
    double S_, V_, t_;

    Camel(double S, double V, double t)
    {
        this->S_ = S;
        this->V_ = V;
        this->t_ = t;
    }

    TRANSPORTSCAMEL_API double rest(/*double S, double V, double t*/);
};