#ifndef SCREENCONSTANS_H
#define SCREENCONSTANS_H
#include <QRect>
class ScreenConstans
{
private:
    QRect   rect;
    int sampleWidth;
    int sampleHeight;
    int widthCheckPoints;
    int heightCheckPoints;
public:
    ScreenConstans(QRect rect, int* sampleHeight, int *sampleWidth);
    int getHeight();
    int getWidth();
    int *getSampleWidth();
    int *getSampleHeight();
    int *getWidthCheckPoints();
    int *getHeihtCheckPoints();
};

#endif // SCREENCONSTANS_H
