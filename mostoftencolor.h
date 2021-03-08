#ifndef MOSTOFTENCOLOR_H
#define MOSTOFTENCOLOR_H

#include <QImage>
#include<stdlib.h>
#include <triplet.h>
#include <screenconstans.h>


class MostOftenColor
{
public:
    MostOftenColor(QImage *d, ScreenConstans *screenconstans,Triplet *triplet, std::vector<Triplet> *mytriplets );
    std::vector<Triplet> getChannels(std::vector<Triplet> *mytriplets);
};

#endif // MOSTOFTENCOLOR_H
