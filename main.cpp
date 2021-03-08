#include <QtCore/QCoreApplication>
//#include <QString>
#include <QtWidgets>
#include <QImage>
#include <QTextStream>
#include <request.h>
#include <vector>

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
    QGuiApplication app(argc, argv);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenres =screen->geometry();

    QPixmap originalPixmap;
    QImage qImage;
    QImage previousImage;
    MostOftenColor* mostoftenColor;

    int sampleWidth = 60;
    int sampleHeight = 60;

    ScreenConstans* screenConstans = new ScreenConstans(screenres, &sampleHeight, &sampleWidth );
    Tuplet tupletToDisplay;
    vector <Triplet> mytriplets;
    Triplet triplet = *new Triplet();
    Triplet choosenTriplet;


    vector <Triplet> *trip;

    //    vector <Triplet> templates;
    //    for(int red=0; red< 256; red+8){
    //        for(int green=0; green< 256; green+8){
    //            for(int blue=0; blue< 256; blue+8){
    //                trip = new Triplet(red,green,blue);
    //                templates.push_back(*trip);
    //            }
    //        }
    //    }




    Request req;

    //    auto start = high_resolution_clock::now();
    //    auto stop = high_resolution_clock::now();

    do{
        usleep(10000);
        //                start = high_resolution_clock::now();

        originalPixmap = screen->grabWindow(0);

        qImage=originalPixmap.toImage();



        MostOftenColor(&qImage,screenConstans,&triplet, &mytriplets);

        //    stop = high_resolution_clock::now();
//        sort(mytriplets.begin(), mytriplets.end(),greater<Triplet>());

//        [&mytriplets,&trip]{
//            bool isOnVector = false;
//            for(int i=0; i<mytriplets.size(); i++){
//                Triplet triplet = mytriplets.at(i);
//                Triplet *triplet2 = new Triplet(triplet.getRed()/8,triplet.getBlue()/8,triplet.getGreen()/8);
//                triplet2->setNumber(triplet.getNumber());

//                for(int j=0; j<trip->size(); j++){
//                    triplet = trip->at(j);
//                    if(triplet.getRed()==triplet2->getRed() && triplet.getGreen()==triplet2->getGreen() && triplet.getBlue()==triplet2->getBlue()){
//                        triplet.addNumber(*triplet2);
//                        isOnVector=true;
//                        break;
//                    }
//                }
//                if(!isOnVector){
//                    trip->push_back(*triplet2);
//                }
//            }
//        };




        ChoosenColorInRGB *chosenColor = new ChoosenColorInRGB(&mytriplets);








        choosenTriplet = *chosenColor->getTheOftenColor();
        tupletToDisplay = choosenTriplet.adjustmentToDisplay();

//                string  resp = new Request(&tupletToDisplay);
//                new Request(&tupletToDisplay);

        Request (tupletToDisplay.getFirst(), tupletToDisplay.getSecond());
        mytriplets.clear();

        //        stop = high_resolution_clock::now();
        //        auto duration = duration_cast<microseconds>(stop - start);
        //        std::cout << "Time taken by function: "
        //                             << duration.count() << " microseconds" << "\n";

        //        previousImage = qImage;
    }while(true);

    return 0;
}

