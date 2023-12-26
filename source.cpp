#include <crow.h>
#include <iostream>
#include <vector>
#include <string>

int main() {
    crow::SimpleApp app;

    std::vector<std::string> cities = {"City1", "City2", "City3", "City4", "City5"};

    CROW_ROUTE(app, "/weather")
        .methods("GET"_method)
        ([&cities](const crow::request& req){
            crow::json::wvalue response;
            for (const auto& city : cities) {
                // In a real-world application, you would fetch the weather data from an API.
                // Here, we simulate the response.
                response[city]["temperature"] = rand() % 30 + 10; // Simulated temperature
            }
            return crow::response{response};
        });

    app.port(8080).multithreaded().run();
    return 0;
}