#include "mostoftencolor.h"


using std::vector;

MostOftenColor::MostOftenColor(Display *d, ScreenConstans *screenconstans,Triplet *triplet, vector<Triplet> *mytriplets)
{
    Screener *screener = new Screener(d, screenconstans->getWidth(), screenconstans->getHeight());

    for (int iwidth = 0; iwidth < screenconstans->getWidthCheckPoints(); iwidth++){
        for (int iheight = 0; iheight < screenconstans->getHeihtCheckPoints(); iheight++){
            bool isOnVector = false;
            Pixel pixel = Pixel(d,screener->getImage(), iwidth, iheight);
            for(int i=0; i<mytriplets->size(); i++){
                triplet = &mytriplets->at(i);
                if(triplet->getRed()==pixel.getRed() && triplet->getGreen()==pixel.getGreen() && triplet->getBlue()==pixel.getBlue()){
                        isOnVector = true;
                        mytriplets->at(i)++;
                }
            }
            if(!isOnVector){
                Triplet trip = *new Triplet(pixel);
                trip++;
                mytriplets->push_back(trip);
            }
        }
    }
    XFree (screener->getImage());
}
