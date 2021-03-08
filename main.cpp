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
    Request req;
    do{
        usleep(10000);
        originalPixmap = screen->grabWindow(0);
        qImage=originalPixmap.toImage();
        MostOftenColor(&qImage,screenConstans,&triplet, &mytriplets);
        ChoosenColorInRGB *chosenColor = new ChoosenColorInRGB(&mytriplets);
        choosenTriplet = *chosenColor->getTheOftenColor();
        tupletToDisplay = choosenTriplet.adjustmentToDisplay();
        Request (tupletToDisplay.getFirst(), tupletToDisplay.getSecond());
        mytriplets.clear();
    }while(true);

    return 0;
}
