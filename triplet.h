#ifndef TRIPLET_H
#define TRIPLET_H
//#include <X11/Xlib.h>
#include <vector>
#include "pixel.h"

class Triplet{

    public:
        bool operator == (Triplet triplet);
        void operator ++ ();
        void operator ++ (int);
        Triplet(Pixel pixel);
        Triplet();
        Triplet(int red, int green, int blue);
        int getRed();
        int getGreen();
        int getBlue();
        int getNumber();
    private:
        int number;
        int red;
        int green;
        int blue;
};

#endif // TRIPLET_H
