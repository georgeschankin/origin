#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSBROOM_API __declspec(dllexport)
#else
#define TRANSPORTSBROOMAPI __declspec(dllimport)
#endif

#include "Air_Transport.h"
class Broomstick :
    public Air_Transport
{
    TRANSPORTSBROOM_API double short_distance(double S);
};

