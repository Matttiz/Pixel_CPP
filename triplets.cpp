#include "triplets.h"

Triplet::Triplet(XColor color){
    this->color = color;
    number = 0;
}

Triplet::Triplet(){
    this->color = *new XColor();
    number = 0;
}

bool Triplet::operator == (Triplet triplet){
  return (this->color.red == triplet.color.red
              && this->color.green == triplet.color.green
              && this->color.blue == triplet.color.blue);
}



