#include "request.h"


//Request::Request(Tuplet* tuplet)
//{

//    auto fileStream = std::make_shared<ostream>();

//    pplx::task<void>  requestTask = fstream::open_ostream(U("results.html")).then([=](ostream outFile)
//    {
//        *fileStream = outFile;

//        http_client client(U("http://192.168.2.176/"));

//        float x = tuplet->getFirst();
//        float y = tuplet->getSecond();



////        float x = 0.2686812222111111111111112222222;
////        float y = 0.3054883333333331222222223333;

//        std::cout << "first " << std::to_string(x) << " Second " << std::to_string(y) << std::endl;


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
//        fileStream.get();
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

Request::Request(float x, float y){
auto fileStream = std::make_shared<ostream>();

pplx::task<void>  requestTask = fstream::open_ostream(U("results.html")).then([=](ostream outFile)
{
    *fileStream = outFile;

    http_client client(U("http://192.168.2.176/"));
//        uri_builder builder(U("/api/68l4z6Au7W-rL3tI3O15XQxlquJWKCYodlolHIdZ/lights/2/state"));

    std::cout << "first " << x << " Second " << y << std::endl;


    json::value obj = json::value::parse(U("{ \"xy\" : [" + std::to_string(x) +"," + std::to_string(y) +"] }"));
    //        header("Content-Type", "application/json")
    http_headers headers= http_headers();
    headers.add(U("Content-Type"), U("application/json"));

    std::string uri = U("/api/68l4z6Au7W-rL3tI3O15XQxlquJWKCYodlolHIdZ/lights/2/state");
    std::cout << uri << std::endl;
    return client.request(methods::PUT, uri,obj);
})

        // Handle response headers arriving.
        .then([=](http_response response)
{
    printf("Received response status code:%u\n", response.status_code());


    // Write response body into the file.
    return response.body().read_to_end(fileStream->streambuf());
})

        // Close the file stream.
        .then([=](size_t)
{
    return fileStream->close();
});

// Wait for all the outstanding I/O to complete and handle any exceptions
try
{
    requestTask.wait();
}
catch (const std::exception &e)
{
    printf("Error exception:%s\n", e.what());
}
}

Request::Request(){

}


Request::Request(Tuplet* tuplet){

          float x = tuplet->getFirst();
          float y = tuplet->getSecond();
            json::value obj = json::value::parse(U("{ \"xy\" : [" + std::to_string(x) +"," + std::to_string(y) +"] }"));
            auto putJson =  http_client(U("http://192.168.2.176/")).
                    request(methods::PUT,
                            uri_builder(U("/api/68l4z6Au7W-rL3tI3O15XQxlquJWKCYodlolHIdZ/lights/2/state")).to_string(),
                            U("{ \"xy\" : [" + std::to_string(x) +"," + std::to_string(y) +"] }"),
                            U("application/json")).then([](http_response response) {
                if (response.status_code() != 200) {
                    throw std::runtime_error("Returned " + std::to_string(response.status_code()));
                }
                    return response.extract_json();
                });
}
