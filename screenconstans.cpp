#include "screenconstans.h"

ScreenConstans::ScreenConstans(int height, int width, int sampleHeight, int sampleWidth)
{
    this->height=height;
    this->width=width;
    this->sampleHeight = sampleHeight;
    this->sampleWidth = sampleWidth;
    this->heightCheckPoints = height/sampleHeight;
    this->widthCheckPoints = width/sampleWidth;
}

int ScreenConstans::getHeight(){
    return height;
}

int ScreenConstans::getWidth(){
    return width;
}

int ScreenConstans::getSampleWidth(){
    return sampleWidth;
}

int ScreenConstans::getSampleHeight(){
    return sampleWidth;
}
int ScreenConstans::getWidthCheckPoints(){
    return widthCheckPoints;
}
int ScreenConstans::getHeihtCheckPoints(){
    return heightCheckPoints;
}
