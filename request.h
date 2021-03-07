#ifndef REQUEST_H
#define REQUEST_H

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <tuplet.h>
#include <string>
#include <boost/algorithm/string/replace.hpp>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams


class Request
{
private:
    string_t response_body;
    int response_code;
public:
    Request(Tuplet* tuplet);
    Request(float x, float y);
    Request();
    string_t getResponseBody();
    int getResponseCode();
};

#endif // REQUEST_H
