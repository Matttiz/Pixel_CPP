#ifndef SCREENER_H
#define SCREENER_H
#include <X11/Xlib.h>
#include <X11/Xutil.h>

class Screener
{
public:
    Screener(Display *display, int width, int height);
    XImage *getImage();
private:
    XImage *image=new XImage();
    int width;
    int height;
};

#endif // SCREENER_H
