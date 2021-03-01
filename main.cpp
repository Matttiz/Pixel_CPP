#include <QtCore/QCoreApplication>
#include <QString>
#include <QTextStream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <vector>
#include <displayer.h>
#include <screener.h>
#include <triplets.h>
#include <pixel.h>
#include<stdlib.h>

using namespace std;

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
    int sampleWidth = 10;
    int sampleHeight = 10;
    int widthCheckPoints = width/sampleWidth;
    int heightCheckPoints = height/sampleHeight;


    vector <Triplet> mytriplets;

    for (int iwidth = 0; iwidth < widthCheckPoints; iwidth++){
        for (int iheight = 0; iheight < heightCheckPoints; iheight++){
            Pixel pixel = Pixel(d,screener->getImage(), iwidth, iheight);

            red = pixel.getRed();
            green= pixel.getGreen();
            blue = pixel.getBlue();

//            XColor x = pixel.getColor();


            cout << red << " " << green << " " << blue << "\n";
        }
    }
    XFree (screener->getImage());
    cout << "Koniec" << Qt::endl;
    return 0;
}
