#include "mostoftencolor.h"


using std::vector;

MostOftenColor::MostOftenColor(QImage *d, ScreenConstans *screenconstans,Triplet *triplet, vector<Triplet> *mytriplets)
{
    Pixel *pixel;
    Triplet trip;
    bool isOnVector = false;
    for (int iwidth = 0; iwidth < *(screenconstans->getWidthCheckPoints()); iwidth++){
        for (int iheight = 0; iheight < *(screenconstans->getHeihtCheckPoints()); iheight++){
            isOnVector = false;
            pixel = new Pixel(d, &iwidth, &iheight);
            for(int i=0; i<mytriplets->size(); i++){
                triplet = &mytriplets->at(i);
                if(triplet->getRed()==pixel->getRed() && triplet->getGreen()==pixel->getGreen() && triplet->getBlue()==pixel->getBlue()){
                    isOnVector = true;
                    mytriplets->at(i)++;
                }
            }
            if(!isOnVector){
                 trip = *new Triplet(*pixel);
                trip++;
                mytriplets->push_back(trip);
            }
            delete pixel;
        }
    }
}
