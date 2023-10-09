#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSCAMEL_API __declspec(dllexport)
#else
#define TRANSPORTSCAMELAPI __declspec(dllimport)
#endif

#include "Land_Transport.h"
class Camel :
    public Land_Transport
{
    TRANSPORTSCAMEL_API double rest(double t);
};

