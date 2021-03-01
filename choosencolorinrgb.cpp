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
