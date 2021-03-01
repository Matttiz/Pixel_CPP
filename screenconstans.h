#ifndef SCREENCONSTANS_H
#define SCREENCONSTANS_H

class ScreenConstans
{
private:
    int height;
    int width;
    int sampleWidth;
    int sampleHeight;
    int widthCheckPoints;
    int heightCheckPoints;
public:
    ScreenConstans(int height, int width, int sampleHeight, int sampleWidth);
    int getHeight();
    int getWidth();
    int getSampleWidth();
    int getSampleHeight();
    int getWidthCheckPoints();
    int getHeihtCheckPoints();
};

#endif // SCREENCONSTANS_H
