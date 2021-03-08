#include "choosencolorinrgb.h"


ChoosenColorInRGB::ChoosenColorInRGB(vector<Triplet> *mytriplets){
    triplets = mytriplets;
}

Triplet* ChoosenColorInRGB::getTheOftenColor(){
    Triplet triplet;
    int maxApperance = 0;
    int pixels = 0;
    for(int i=0; i<triplets->size(); i++){
        pixels += triplets-> at(i).getNumber();
        if(maxApperance < triplets-> at(i).getNumber()){
            maxApperance = triplets-> at(i).getNumber();
            triplet = triplets-> at(i);
        }
    }
    return new Triplet(triplet);
}

void ChoosenColorInRGB::getNotChannelColor(){
    std::vector<Triplet> newOne;
    for(int i=0; i<triplets->size(); i++){
        newOne.push_back(*new Triplet(triplets->at(i).getRed()*8 + 4,triplets->at(i).getGreen()*8 + 4,triplets->at(i).getRed()*8 + 4,triplets->at(i).getNumber()));
    }
    triplets=&newOne;
}
