#include "pixel.h"

Pixel::Pixel(Display *display,XImage* image, int* width, int* height)
{
    color.pixel = XGetPixel (image, *width, *height);
    XQueryColor (display, XDefaultColormap(display, XDefaultScreen (display)), &color);
}

Pixel::Pixel(){

}

XColor Pixel::getColor(){
    return color;
}

int Pixel::getRed(){
    return (int) color.red/256;
}

int Pixel::getGreen(){
    return (int) color.green/256;
}
int Pixel::getBlue(){
    return (int) color.blue/256;
}

bool Pixel::operator == (Pixel pixel){
    return (this->color.red == pixel.color.red
            && this->color.green == pixel.color.green
            && this->color.blue == pixel.color.blue);
}
