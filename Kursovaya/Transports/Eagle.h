#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSEAGLE_API __declspec(dllexport)
#else
#define TRANSPORTSEAGLEAPI __declspec(dllimport)
#endif

#include "Air_Transport.h"
class Eagle :
    public Air_Transport
{
    TRANSPORTSEAGLE_API double short_distance(double S);
};

