#include "pixel.h"

Pixel::Pixel(QImage* image, int* width, int* height)
{

    QColor rgb = image->pixel(*width,*height);
    rgb.getRgb(&red,&green,&blue);
    if(red>256 || green > 256 || blue > 256){
        return;
    }
}

Pixel::Pixel(int red, int green, int blue){
    red=0;
    green=0;
    blue=0;
}


int Pixel::getRed(){
    return red;
}

int Pixel::getGreen(){
    return green;
}
int Pixel::getBlue(){
    return blue;
}

bool Pixel::operator == (Pixel pixel){
    return (red == pixel.red
            && green == pixel.green
            && blue == pixel.blue);
}
