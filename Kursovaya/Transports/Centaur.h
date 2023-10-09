#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSCENTAUR_API __declspec(dllexport)
#else
#define TRANSPORTSCENTAURAPI __declspec(dllimport)
#endif

#include "Land_Transport.h"
class Centaur :
    public Land_Transport
{
    TRANSPORTSCENTAUR_API double rest(double t);
};

