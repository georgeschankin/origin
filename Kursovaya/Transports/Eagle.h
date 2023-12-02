#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSEAGLE_API __declspec(dllexport)
#else
#define TRANSPORTSEAGLE_API __declspec(dllimport)
#endif

#include "Air_Transport.h"
class Eagle : public Air_Transport
{
public:
    TRANSPORTSEAGLE_API static double short_distance(double S);
};

