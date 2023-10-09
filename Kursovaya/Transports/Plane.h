#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSPLANE_API __declspec(dllexport)
#else
#define TRANSPORTSPLANEAPI __declspec(dllimport)
#endif

#include "Air_Transport.h"
class Plane :
    public Air_Transport
{
    TRANSPORTSPLANE_API double short_distance(double S);
};

