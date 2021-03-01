#ifndef DISPLAYER_H
#define DISPLAYER_H
#include <X11/Xlib.h>
#include <X11/Xutil.h>

class Displayer
{
private:
    int width;
    int height;
public:
    Displayer(Display *display);
    int getWidth();
    int getHeight();
};

#endif // DISPLAYER_H
