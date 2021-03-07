#include "screener.h"

Screener::Screener(Display *display, int *height, int *width)
{
    this->width = width;
    this->height = height;
//    *image = *new XImage();
    image = XGetImage (display, XRootWindow
                       (display, XDefaultScreen (display)),
                       0, 0, *height, *width, AllPlanes, XYPixmap);
}

XImage* Screener::getImage(){
    return image;
}
