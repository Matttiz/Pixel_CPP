#include <QtCore/QCoreApplication>
#include <QString>
#include <QTextStream>
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
    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);
    Display *d = XOpenDisplay((char *) NULL);
    Displayer *displayer = new Displayer(d);

    MostOftenColor* mostoftenColor;

    int height = displayer->getHeight();
    int width = displayer->getWidth();
    int sampleWidth = 30;
    int sampleHeight = 30;

    ScreenConstans* screenConstans = new ScreenConstans(height, width, sampleHeight, sampleWidth );

    vector <Triplet> mytriplets;
    Triplet triplet = *new Triplet();
    mytriplets.push_back(triplet);
    Triplet choosenTriplet;


//    cout << "Time taken by function: "<<Qt::endl;
//    auto start = high_resolution_clock::now();

    mostoftenColor =  new MostOftenColor(d,screenConstans,&triplet, &mytriplets);

//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << "Time taken by function: "
//             << duration.count() << " microseconds" << Qt::endl;


    ChoosenColorInRGB *chosenColor = new ChoosenColorInRGB(&mytriplets);
    choosenTriplet = *chosenColor->getTheOftenColor();



        cout << "The most popular "<< Qt::endl;
        cout << choosenTriplet.getRed() << " " << choosenTriplet.getGreen() << " " << choosenTriplet.getBlue() << "\n";
        cout << choosenTriplet.getNumber() << "\n";

    cout << "Koniec" << Qt::endl;
    return 0;
}
