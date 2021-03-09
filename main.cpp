#include <QtCore/QCoreApplication>
#include <QtWidgets>
#include <QImage>
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
//    QImage previousImage;
    MostOftenColor* mostoftenColor;

    int sampleWidth = 60;
    int sampleHeight = 60;

    ScreenConstans* screenConstans = new ScreenConstans(screenres, &sampleHeight, &sampleWidth );
    Tuplet tupletToDisplay;
    vector <Triplet> mytriplets;
    Triplet triplet = *new Triplet();
    Triplet choosenTriplet;

    Request req;

//    auto start = high_resolution_clock::now();
//    auto stop = high_resolution_clock::now();

    do{
          usleep(50000);
//                start = high_resolution_clock::now();

        originalPixmap = screen->grabWindow(0);

        qImage=originalPixmap.toImage();



        MostOftenColor(&qImage,screenConstans,&triplet, &mytriplets);



        //    stop = high_resolution_clock::now();

        ChoosenColorInRGB *chosenColor = new ChoosenColorInRGB(&mytriplets);

//         sort(mytriplets.begin(), mytriplets.end());


        choosenTriplet = *chosenColor->getTheOftenColor();
        tupletToDisplay = choosenTriplet.adjustmentToDisplay();

//        string  resp = new Request(&tupletToDisplay);
//        new Request(&tupletToDisplay);

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

