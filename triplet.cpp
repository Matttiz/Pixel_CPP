#include "triplet.h"

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

//bool operator < (Triplet triplet1, Triplet triplet2){
//    if(triplet1.getNumber() <triplet2.getNumber()){
//        return true;
//    }else{
//        return false;
//    }
//};

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

//void Triplet::setNumber(int numb){
//    number=numb;
//}

//void Triplet::addNumber(Triplet triplet){
//    this->number+=triplet.getNumber();
//}

Tuplet Triplet::adjustmentToDisplay(){
            float red = (getRed() > 0.04045f) ? (float) pow((getRed() + 0.055f) / (1.0f + 0.055f), 2.4f) : (getRed() / 12.92f);
            float green = (getGreen() > 0.04045f) ? (float) pow((getGreen() + 0.055f) / (1.0f + 0.055f), 2.4f) : (getGreen()/ 12.92f);
            float blue = (getBlue() > 0.04045f) ? (float) pow((getBlue() + 0.055f) / (1.0f + 0.055f), 2.4f) : (getBlue() / 12.92f);

            float X = red * 0.649926f + green * 0.103455f + blue * 0.197109f;
            float Y = red * 0.234327f + green * 0.743075f + blue * 0.022598f;
            float Z = red * 0.0000000f + green * 0.053077f + blue * 1.035763f;

            float x = X / (X + Y + Z);
            float y = Y / (X + Y + Z);

            return *new Tuplet (x, y);
}
