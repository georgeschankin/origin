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
    double S_, V_, t_;

    Centaur(double S, double V, double t)
    {
        this->S_ = S;
        this->V_ = V;
        this->t_ = t;
    }
    TRANSPORTSCENTAUR_API double rest(/*double S, double V, double t*/);
};

