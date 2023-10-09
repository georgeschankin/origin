#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSBOOTS_API __declspec(dllexport)
#else
#define TRANSPORTSBOOTSAPI __declspec(dllimport)
#endif

#include "Land_Transport.h"
class Boots :
    public Land_Transport
{
    TRANSPORTSBOOTS_API double rest(double t);
};

