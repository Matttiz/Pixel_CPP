#include "tuplet.h"

Tuplet::Tuplet()
{
    firstValue=0.0;
    secondValue=0.0;
}


Tuplet::Tuplet(float first, float second)
{
    firstValue =first;
    secondValue=second;
}

float Tuplet::getFirst(){
    return firstValue;
}

float Tuplet::getSecond(){
    return secondValue;
}
