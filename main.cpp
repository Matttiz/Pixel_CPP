#include <QtCore/QCoreApplication>
#include <QString>
#include <QTextStream>
#include <vector>
#include<stdlib.h>
#include <displayer.h>
#include <screener.h>
#include <triplets.h>
#include <pixel.h>
#include <algorithm>
#include <chrono>
#include <iostream>


using namespace std;
using namespace std::chrono;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);
    Display *d = XOpenDisplay((char *) NULL);
    Displayer *displayer = new Displayer(d);

    int height = displayer->getHeight();
    int width = displayer->getWidth();

    Screener *screener = new Screener(d, width, height);
    int red;
    int green;
    int blue;
    int sampleWidth = 30;
    int sampleHeight = 30;
    int widthCheckPoints = width/sampleWidth;
    int heightCheckPoints = height/sampleHeight;


    vector <Triplet> mytriplets;
    Triplet triplet = *new Triplet();

    mytriplets.push_back(triplet);

    cout << "Time taken by function: "<<Qt::endl;
    auto start = high_resolution_clock::now();

    for (int iwidth = 0; iwidth < widthCheckPoints; iwidth++){
        for (int iheight = 0; iheight < heightCheckPoints; iheight++){
            Pixel pixel = Pixel(d,screener->getImage(), iwidth, iheight);
            find(mytriplets.begin(), mytriplets.end(), pixel);
            red = pixel.getRed();
            green= pixel.getGreen();
            blue = pixel.getBlue();


//            XColor x = pixel.getColor();


//            cout << red << " " << green << " " << blue << "\n";
        }
    }
    XFree (screener->getImage());

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
             << duration.count() << " microseconds" << Qt::endl;

    cout << "Koniec" << Qt::endl;
    return 0;
}
