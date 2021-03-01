#ifndef PIXEL_H
#define PIXEL_H
#include <X11/Xlib.h>
#include <X11/Xutil.h>

class Pixel{
private:
    XColor color;
    Display *display;
public:
    Pixel(Display *display,XImage* image, int width, int height);
    bool operator == (Pixel pixel);
    XColor getColor();
    int getRed();
    int getGreen();
    int getBlue();
};
#endif // PIXEL_H
