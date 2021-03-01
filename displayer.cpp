#include "displayer.h"

Displayer::Displayer(Display *display)
{
    XWindowAttributes windowAttributes;
    XGetWindowAttributes(display, DefaultRootWindow(display), &windowAttributes);
    width = windowAttributes.width;
    height = windowAttributes.height;
}

int Displayer::getHeight(){
    return height;
}

int Displayer::getWidth(){
    return width;
}


