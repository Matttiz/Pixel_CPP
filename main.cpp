#include <QtCore/QCoreApplication>
//#include <QString>
#include <QTextStream>
#include <request.h>
#include <vector>

#include <displayer.h>
#include <screener.h>
#include <triplet.h>
#include <pixel.h>
#include <screenconstans.h>
#include <mostoftencolor.h>
#include <choosencolorinrgb.h>

#include <algorithm>
#include <chrono>


using namespace std;
using namespace std::chrono;


int main(int argc, char *argv[])
{
    //    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);
    Display *d = XOpenDisplay((char *) NULL);
    Displayer displayer = *new Displayer(d);

//    MostOftenColor* mostoftenColor;

    int height = displayer.getHeight();
    int width = displayer.getWidth();
    int sampleWidth = 200;
    int sampleHeight = 200;

    ScreenConstans* screenConstans = new ScreenConstans(&height, &width, &sampleHeight, &sampleWidth );
    Tuplet tupletToDisplay;
    vector <Triplet> mytriplets;
    Triplet triplet = *new Triplet();
    Triplet choosenTriplet;

    //    Request req;
//    auto start = high_resolution_clock::now();
//    auto stop = high_resolution_clock::now();
//    int i =0;
    do{
//        start = high_resolution_clock::now();
                        usleep(1000);
        //    mytriplets.push_back(triplet);
        //    cout << "Time taken by function: "<<Qt::endl;
        //    auto start = high_resolution_clock::now();

        MostOftenColor(d,screenConstans,&triplet, &mytriplets);

        //    auto stop = high_resolution_clock::now();



        ChoosenColorInRGB *chosenColor = new ChoosenColorInRGB(&mytriplets);
        choosenTriplet = *chosenColor->getTheOftenColor();
        tupletToDisplay = choosenTriplet.adjustmentToDisplay();



        new Request(&tupletToDisplay);

        mytriplets.clear();

//        delete displayer;
        //        delete triplet;
        //        delete d;
//        stop = high_resolution_clock::now();
//        auto duration = duration_cast<microseconds>(stop - start);
//        cout << "Time taken by function: "
//                     << duration.count() << " microseconds" << Qt::endl;
//        if (i %100){
//            cout << i << Qt::endl;
//        }
    }while(true);

//    cout << "The most popular "<< Qt::endl;
//    cout << choosenTriplet.getRed() << " " << choosenTriplet.getGreen() << " " << choosenTriplet.getBlue() << "\n";
//    cout << choosenTriplet.getNumber() << "\n";

//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << "Time taken by function: "
//                 << duration.count() << " microseconds" << Qt::endl;


    cout << "Koniec" << Qt::endl;
    return 0;
}

