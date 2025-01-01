#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include "FuncA.h"

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

// HTTP request handler
void handle_compute(http_request request) {
    auto query = uri::split_query(request.request_uri().query());

    auto start_time = std::chrono::high_resolution_clock::now();

    // Perform computation
    FuncA func;
    std::vector<double> result_array;

    // Iterate over x
    for (int x = 1; x <= 100; ++x) {
        // Iterate over n
        for (int n = 1000; n <= 2000; ++n) {
            // Perform calculation and store in result array
            result_array.push_back(func.calculate(static_cast<double>(x), n));
        }
    }

    // Sort the results
    std::sort(result_array.begin(), result_array.end());

    // Measure elapsed time
    auto end_time = std::chrono::high_resolution_clock::now();
    double elapsed_time = std::chrono::duration<double>(end_time - start_time).count();

    // Log computation details
    std::cout << "Computation completed in " << elapsed_time << std::endl;

    // Create JSON response
    json::value response;
    response[U("elapsed_time")] = json::value::number(elapsed_time);

    // Send response
    request.reply(status_codes::OK, response);
}

int main() {
    http_listener listener(U("http://0.0.0.0:8080/compute"));

    // Bind the `/compute` route to the handler
    listener.support(methods::GET, handle_compute);

    try {
        listener
            .open()
            .then([]() { std::cout << "Server is running on port 8080..." << std::endl; })
            .wait();

        while (true); // Keep the server running
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
