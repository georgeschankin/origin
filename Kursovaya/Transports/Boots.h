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
    double S_, V_, t_;

    Boots(double S, double V, double t)
    {
        this->S_ = S;
        this->V_ = V;
        this->t_ = t;
    }

    TRANSPORTSBOOTS_API double rest(/*double S, double V, double t*/);
};

