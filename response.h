#ifndef RESPONSE_H
#define RESPONSE_H

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>
#include <tuplet.h>
#include <string>

using namespace utility;                    // Common utilities like string conversions
//using namespace web;                        // Common features like URIs.
//using namespace web::http;                  // Common HTTP functionality
//using namespace web::http::client;          // HTTP client features
//using namespace concurrency::streams;       // Asynchronous streams


class Response
{
private:
    string_t response_body;
    int resposnse_code;
public:
    Response();
    int getResponseCode();

};

#endif // RESPONSE_H
