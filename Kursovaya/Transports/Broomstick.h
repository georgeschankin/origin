#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSBROOM_API __declspec(dllexport)
#else
#define TRANSPORTSBROOM_API __declspec(dllimport)
#endif

#include "Air_Transport.h"
class Broomstick :
    public Air_Transport
{
public:
    TRANSPORTSBROOM_API static double short_distance(double S);
};

