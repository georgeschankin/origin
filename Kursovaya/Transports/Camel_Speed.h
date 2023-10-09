#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSCAMELSPEED_API __declspec(dllexport)
#else
#define TRANSPORTSCAMELSPEEDAPI __declspec(dllimport)
#endif

#include "Land_Transport.h"
class Camel_Speed :
    public Land_Transport
{
    TRANSPORTSCAMELSPEED_API double rest(double t);
};

