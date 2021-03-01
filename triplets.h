#ifndef TRIPLETS_H
#define TRIPLETS_H
#include <X11/Xlib.h>
#include <vector>

class Triplet{
    public:
        bool operator == (Triplet triplet);
        Triplet(XColor color);
    private:
        XColor color;
        int number;
};

#endif // TRIPLETS_H
