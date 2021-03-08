#include "request.h"

//using namespace std;
using namespace boost;

Request::Request(float x, float y){
    auto fileStream = std::make_shared<ostream>();

    std::string xAsString = std::to_string(x);
    replace_all(xAsString, ",",".");
    std::string yAsString = std::to_string(y);
    replace_all(yAsString, ",",".");
    std::cout << "{ \"xy\" : [" + xAsString +"," + yAsString +"] }" << '\n';
    pplx::task<void>  requestTask = fstream::open_ostream(U("results.html")).then([=](ostream outFile)
    {
        *fileStream = outFile;

        http_client client(U("http://192.168.2.176/"));
        json::value obj = json::value::parse(U("{ \"xy\" : [" + xAsString +"," + yAsString +"] }"));
        http_headers headers= http_headers();
        headers.add(U("Content-Type"), U("application/json"));
        std::string uri = U("/api/68l4z6Au7W-rL3tI3O15XQxlquJWKCYodlolHIdZ/lights/2/state");
//        std::cout << uri << std::endl;
        return client.request(methods::PUT, uri,obj);
    })
            // Handle response headers arriving.
            .then([=](http_response response)
    {
//        printf("Received response status code:%u\n", response.status_code());
        // Write response body into the file.
        std::string strea;
        strea = response.extract_string().get();
            std::cout << strea<< std::endl;
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


    std::string xAsString = std::to_string(x);
    replace_all(xAsString, ",",".");
    std::string yAsString = std::to_string(y);
    replace_all(yAsString, ",",".");

    string_t string;
    json::value obj = json::value::parse(U("{ \"xy\" : [" + xAsString +"," + yAsString +"] }"));

    int code;
    std::string body;
    string_t bod;
    auto putJson =  http_client(U("http://192.168.2.176/")).
            request(methods::PUT,
                    uri_builder(U("/api/68l4z6Au7W-rL3tI3O15XQxlquJWKCYodlolHIdZ/lights/2/state")).to_string(),
                    U("{ \"xy\" : [" + xAsString +"," + yAsString +"] }"),
                    U("application/json")).then([&code, &bod](http_response response) {
        code = response.status_code();
        if (code != 200) {
            throw std::runtime_error("Returned " + std::to_string(code));
        }

        bod = response.extract_string().get();
        std::cout << code << '\n';
        std::cout << bod << '\n';
        return response.extract_json();
    });
    //            try
    //    {
    //        requestTask.wait();
    //    }
    //    catch (const std::exception &e)
    //    {
    //        printf("Error exception:%s\n", e.what());
    //    }
    response_code = code;
    response_body = bod;
}
