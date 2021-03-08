#ifndef PIXEL_H
#define PIXEL_H
//#include <X11/Xutil.h>
#include <QImage>
#include <QPixelFormat>

class Pixel{
private:
    int red;
    int green;
    int blue;

public:
    Pixel(QImage *image, int *width, int* height);
    Pixel();
    Pixel(int red, int green, int blue);
    bool operator == (Pixel pixel);
    int getRed();
    int getGreen();
    int getBlue();
};
#endif // PIXEL_H
