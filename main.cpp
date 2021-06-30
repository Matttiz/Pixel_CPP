#include <QtCore/QCoreApplication>
#include <QtWidgets>
#include <QImage>
#include <QSize>
#include <request.h>
#include <vector>

#include <triplet.h>
#include <pixel.h>
#include <screenconstans.h>
#include <mostoftencolor.h>
#include <choosencolorinrgb.h>
#include <request.h>

using namespace std;
using namespace std::chrono;


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenres =screen->geometry();
    QSize qsize = *new QSize(screenres.center().x()+1,screenres.center().y()+1);
    screenres.setSize(qsize);


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

//    Request req;
    do{
        usleep(10000);
        originalPixmap = screen->grabWindow(0);
        qImage=originalPixmap.toImage();
        MostOftenColor most =  MostOftenColor(&qImage,screenConstans,&triplet, &mytriplets);
        ChoosenColorInRGB *chosenColor = new ChoosenColorInRGB(&mytriplets);


        choosenTriplet = *chosenColor->getTheOftenColor();
        tupletToDisplay = choosenTriplet.adjustmentToDisplay();
        Request(tupletToDisplay);
//        Request (tupletToDisplay.getFirst(), tupletToDisplay.getSecond());

        mytriplets.clear();

    }while(true);

    return 0;
}
