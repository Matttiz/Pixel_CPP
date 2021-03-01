#ifndef CHOOSENCOLORINRGB_H
#define CHOOSENCOLORINRGB_H

#include "triplet.h"

using std::vector;

class ChoosenColorInRGB
{
private:
    vector<Triplet> *triplets;
public:
    ChoosenColorInRGB(vector<Triplet> *mytriplets );
    Triplet* getTheOftenColor();
};

#endif // CHOOSENCOLORINRGB_H
