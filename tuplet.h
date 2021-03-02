#ifndef TUPLET_H
#define TUPLET_H


class Tuplet
{
private:
    float firstValue;
    float secondValue;
public:
    Tuplet();
    Tuplet(float first, float second);
    float getFirst();
    float getSecond();
};

#endif // TUPLET_H
