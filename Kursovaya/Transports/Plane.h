#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSPLANE_API __declspec(dllexport)
#else
#define TRANSPORTSPLANE_API __declspec(dllimport)
#endif

#include "Air_Transport.h"
class Plane : public Air_Transport
{
public:
    TRANSPORTSPLANE_API static double short_distance(double S);
};

