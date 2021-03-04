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
    Displayer *displayer = new Displayer(d);

//    MostOftenColor* mostoftenColor;

    int height = displayer->getHeight();
    int width = displayer->getWidth();
    int sampleWidth = 200;
    int sampleHeight = 200;

    ScreenConstans* screenConstans = new ScreenConstans(height, width, sampleHeight, sampleWidth );
    Tuplet tupletToDisplay;
    vector <Triplet> mytriplets;
    Triplet triplet = *new Triplet();
    Triplet choosenTriplet;

    //    Request req;
//    auto start = high_resolution_clock::now();
//    auto stop = high_resolution_clock::now();
    do{
//        start = high_resolution_clock::now();
        //                usleep(500);
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

        delete displayer;
        //        delete triplet;
        //        delete d;
//        stop = high_resolution_clock::now();
//        auto duration = duration_cast<microseconds>(stop - start);
//        cout << "Time taken by function: "
//                     << duration.count() << " microseconds" << Qt::endl;
    }while(true);

    cout << "The most popular "<< Qt::endl;
    cout << choosenTriplet.getRed() << " " << choosenTriplet.getGreen() << " " << choosenTriplet.getBlue() << "\n";
    cout << choosenTriplet.getNumber() << "\n";

//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << "Time taken by function: "
//                 << duration.count() << " microseconds" << Qt::endl;


    cout << "Koniec" << Qt::endl;
    return 0;
}

//#include <cpprest/http_client.h>
//#include <cpprest/filestream.h>
//#include <tuplet.h>

//using namespace utility;                    // Common utilities like string conversions
//using namespace web;                        // Common features like URIs.
//using namespace web::http;                  // Common HTTP functionality
//using namespace web::http::client;          // HTTP client features
//using namespace concurrency::streams;       // Asynchronous streams


//int main(){

//    auto fileStream = std::make_shared<ostream>();

//    pplx::task<void>  requestTask = fstream::open_ostream(U("results.html")).then([=](ostream outFile)
//    {
//        *fileStream = outFile;

//        http_client client(U("http://192.168.2.176/"));
//        //        uri_builder builder(U("/api/68l4z6Au7W-rL3tI3O15XQxlquJWKCYodlolHIdZ/lights/2/state"));


//        float x = 0.28900522;
//        float y = 0.31871283;

//        std::cout << "first " << x << " Second " << y << std::endl;


//        json::value obj = json::value::parse(U("{ \"xy\" : [" + std::to_string(x) +"," + std::to_string(y) +"] }"));
//        //        header("Content-Type", "application/json")
//        http_headers headers= http_headers();
//        headers.add(U("Content-Type"), U("application/json"));

//        std::string uri = U("/api/68l4z6Au7W-rL3tI3O15XQxlquJWKCYodlolHIdZ/lights/2/state");
//        std::cout << uri << std::endl;
//        return client.request(methods::PUT, uri,obj);
//    })

//            // Handle response headers arriving.
//            .then([=](http_response response)
//    {
//        printf("Received response status code:%u\n", response.status_code());


//        // Write response body into the file.
//        return response.body().read_to_end(fileStream->streambuf());
//    })

//            // Close the file stream.
//            .then([=](size_t)
//    {
//        return fileStream->close();
//    });

//    // Wait for all the outstanding I/O to complete and handle any exceptions
//    try
//    {
//        requestTask.wait();
//    }
//    catch (const std::exception &e)
//    {
//        printf("Error exception:%s\n", e.what());
//    }
//}
