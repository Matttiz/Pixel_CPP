#ifndef MOSTOFTENCOLOR_H
#define MOSTOFTENCOLOR_H

#include<stdlib.h>
#include <screener.h>
#include <triplet.h>
#include <screenconstans.h>

class MostOftenColor
{
public:
    MostOftenColor(Display *d, ScreenConstans *screenconstans,Triplet *triplet, std::vector<Triplet> *mytriplets );
};

#endif // MOSTOFTENCOLOR_H
