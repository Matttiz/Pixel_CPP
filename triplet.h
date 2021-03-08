#ifndef TRIPLET_H
#define TRIPLET_H
//#include <X11/Xlib.h>
#include <vector>
#include "pixel.h"
#include <math.h>
#include "tuplet.h"

class Triplet{

    public:
        bool operator == (Triplet triplet);
        bool operator < (Triplet triplet);
//        Triplet operator % (int);
        Triplet setToChannel(int);
        void operator ++ ();
        void operator ++ (int);
        Triplet(Pixel pixel);
        Triplet();
        Triplet(int red, int green, int blue, int number);
        int getRed();
        int getGreen();
        int getBlue();
        int getNumber();
        void setNumber(int numb);
        void addNumber(Triplet triplet);

        Tuplet adjustmentToDisplay ();
    private:
        int number;
        int red;
        int green;
        int blue;
};

#endif // TRIPLET_H
