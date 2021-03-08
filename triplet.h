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
        bool operator > (const Triplet &triplet) const;
        void operator ++ ();
        void operator ++ (int);
        Triplet(Pixel pixel);
        Triplet();
        Triplet(Triplet const &trip);
        Triplet(int red, int green, int blue);
        int getRed();
        int getGreen();
        int getBlue();
        int getNumber();
        void setNumber(int number);
        void addNumber(Triplet triplet);
        Tuplet adjustmentToDisplay ();
    private:
        int number;
        int red;
        int green;
        int blue;
};

#endif // TRIPLET_H
