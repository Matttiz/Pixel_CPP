#ifndef TRIPLETS_H
#define TRIPLETS_H
#include <X11/Xlib.h>
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
//        XColor color;
        int number;

        int red;
        int green;
        int blue;

};

#endif // TRIPLETS_H
