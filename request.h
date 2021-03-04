#ifndef REQUEST_H
#define REQUEST_H

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <tuplet.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams


class Request
{
private:

public:
    Request(Tuplet* tuplet);
    Request(float x, float y);
    Request();
};

#endif // REQUEST_H
