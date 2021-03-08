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
                    break;
                }
            }
            if(!isOnVector){
                trip = *new Triplet(*pixel);
                trip++;
                mytriplets->push_back(trip);
//                mytriplets->push_back(*new Triplet(*pixel));
            }
            delete pixel;
        }
    }
}


std::vector<Triplet> MostOftenColor::getChannels(std::vector<Triplet> *mytriplets){
    Triplet triplet;
    Triplet tripletChannel;
    vector<Triplet> channelVector;
    bool isOnVector = false;
    for(int i=0; i<mytriplets->size(); i++){
        triplet = mytriplets->at(i);
        tripletChannel = triplet.setToChannel(8);
        for(int j = 0; j< channelVector.size();j++){
            if(channelVector.at(j) == tripletChannel){
                channelVector.at(j).addNumber(tripletChannel);
                isOnVector = true;
                break;
            }
        }
        if(!isOnVector){
            channelVector.push_back(tripletChannel);
        }
        isOnVector = false;
    }
    return channelVector;
}
