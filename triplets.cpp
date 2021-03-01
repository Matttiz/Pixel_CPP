#include "triplets.h"
#include "pixel.h"

Triplet::Triplet(Pixel pixel){
    this->red=pixel.getRed();
    this->green=pixel.getGreen();
    this->blue=pixel.getBlue();
    this->number = 0;
}

Triplet::Triplet(){
    this->red=0;
    this->green=0;
    this->blue=0;
    this->number = 0;
}



bool Triplet::operator == (Triplet triplet){
  return (this->red == triplet.red
              && this->green == triplet.green
              && this->blue == triplet.blue);
}

void Triplet::operator ++ (){
    number++;
}

void Triplet::operator ++ (int){
    number++;
}

int Triplet::getRed(){
    return red;
}

int Triplet::getGreen(){
    return green;
}

int Triplet::getBlue(){
    return blue;
}

int Triplet::getNumber(){
    return number;
}
//XColor Triplet::getColor(){
//    return this->color;
//}




