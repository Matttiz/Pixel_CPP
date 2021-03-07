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

    int sampleWidth = 50;
    int sampleHeight = 50;

    ScreenConstans* screenConstans = new ScreenConstans(screenres, &sampleHeight, &sampleWidth );
    Tuplet tupletToDisplay;
    vector <Triplet> mytriplets;
    Triplet triplet = *new Triplet();
    Triplet choosenTriplet;

    Request req;

    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    int i =0;

    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    if (initialPath.isEmpty())
        initialPath = QDir::currentPath();

    do{

        usleep(10000);
        originalPixmap = screen->grabWindow(0);

        qImage=originalPixmap.toImage();
        //    cout << "Time taken by function: "<<Qt::endl;
        auto start = high_resolution_clock::now();

        MostOftenColor(&qImage,screenConstans,&triplet, &mytriplets);

        //    auto stop = high_resolution_clock::now();


        ChoosenColorInRGB *chosenColor = new ChoosenColorInRGB(&mytriplets);
        choosenTriplet = *chosenColor->getTheOftenColor();
        tupletToDisplay = choosenTriplet.adjustmentToDisplay();



        new Request(&tupletToDisplay);

        mytriplets.clear();

        stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function: "
                             << duration.count() << " microseconds" << "\n";
        //        if (i %100){
        //            cout << i << Qt::endl;
        //        }

        cout << "The most popular "<< "\n";
        cout << choosenTriplet.getRed() << " " << choosenTriplet.getGreen() << " " << choosenTriplet.getBlue() << "\n";
        cout << choosenTriplet.getNumber() << "\n";
        cout << "Replay " << i << "\n";

        i++;

        previousImage = qImage;
    }while(true);

    cout << "The most popular "<< &Qt::endl;
    cout << choosenTriplet.getRed() << " " << choosenTriplet.getGreen() << " " << choosenTriplet.getBlue() << "\n";
    cout << choosenTriplet.getNumber() << "\n";

    //    auto duration = duration_cast<microseconds>(stop - start);
    //    cout << "Time taken by function: "
    //                 << duration.count() << " microseconds" << Qt::endl;


    cout << "Koniec" << &Qt::endl;

    //    return app.exec();
    return 0;
}

