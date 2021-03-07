#include "screenconstans.h"


ScreenConstans::ScreenConstans(QRect rect, int *sampleHeight, int *sampleWidth)
{
    this->rect = rect;
    this->sampleHeight = *sampleHeight;
    this->sampleWidth = *sampleWidth;
    this->heightCheckPoints = (rect.height())/(*sampleHeight);
    this->widthCheckPoints = (rect.width())/(*sampleWidth);
}

int ScreenConstans::getHeight(){
    return rect.height();
}

int ScreenConstans::getWidth(){
    return rect.width();
}

int* ScreenConstans::getSampleWidth(){
    return &sampleWidth;
}

int* ScreenConstans::getSampleHeight(){
    return &sampleWidth;
}
int* ScreenConstans::getWidthCheckPoints(){
    return &widthCheckPoints;
}
int* ScreenConstans::getHeihtCheckPoints(){
    return &heightCheckPoints;
}
