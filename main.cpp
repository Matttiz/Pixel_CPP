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
    int sampleWidth = 30;
    int sampleHeight = 30;

    int widthCheckPoints = width/sampleWidth;
    int heightCheckPoints = height/sampleHeight;

    vector <Triplet> mytriplets;
    Triplet triplet = *new Triplet();
    mytriplets.push_back(triplet);

    //

    Screener *screener = new Screener(d, width, height);

    cout << "Time taken by function: "<<Qt::endl;
    auto start = high_resolution_clock::now();

    for (int iwidth = 0; iwidth < widthCheckPoints; iwidth++){
        for (int iheight = 0; iheight < heightCheckPoints; iheight++){
            bool isOnVector = false;
            Pixel pixel = Pixel(d,screener->getImage(), iwidth, iheight);
            for(int i=0; i<mytriplets.size(); i++){
                triplet = mytriplets[i];
                if(triplet.getRed()==pixel.getRed() && triplet.getGreen()==pixel.getGreen() && triplet.getBlue()==pixel.getBlue()){
                        isOnVector = true;
                        mytriplets[i]++;
                }
            }
            if(!isOnVector){
                Triplet trip = *new Triplet(pixel);
                trip++;
                mytriplets.push_back(trip);
            }
        }
    }
    XFree (screener->getImage());
    //


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
             << duration.count() << " microseconds" << Qt::endl;


    for(int i=0; i<mytriplets.size(); i++){
        triplet = mytriplets[i];
        cout << "Kolor is " <<Qt::endl;
        cout <<  triplet.getRed() << " " << triplet.getGreen() << " " << triplet.getBlue() << "\n";

        cout << triplet.getNumber() << Qt::endl;

    }
        int maxApperance = 0;
        int pixels = 0;
        for(int i=0; i<mytriplets.size(); i++){
            pixels += mytriplets[i].getNumber();
            if(maxApperance < mytriplets[i].getNumber()){
                maxApperance = mytriplets[i].getNumber();
                triplet = mytriplets[i];
            }
        }
        cout << "should be" << widthCheckPoints*heightCheckPoints<<Qt::endl;
        cout << "pixels " << pixels<<Qt::endl;
        cout << "Kolor is " <<Qt::endl;
        cout <<  triplet.getRed() << " " << triplet.getGreen() << " " << triplet.getBlue() << "\n";

        cout << triplet.getNumber() << Qt::endl;

    cout << "Koniec" << Qt::endl;
    return 0;
}
