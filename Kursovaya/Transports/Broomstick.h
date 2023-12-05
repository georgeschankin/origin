#pragma once
#ifdef TRANSPORTS_EXPORTS
#define TRANSPORTSBROOM_API __declspec(dllexport)
#else
#define TRANSPORTSBROOM_API __declspec(dllimport)
#endif

#include "Air_Transport.h"
class Broomstick : public Air_Transport
{
public:
    double S_;

    Broomstick(double S)
    {
        this->S_ = S;
    }
    TRANSPORTSBROOM_API double short_distance(/*double S*/);
};

