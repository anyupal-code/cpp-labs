#include "tracked_string.h"
#include "logger.h"

#include <iostream>
#include <string>

int main() {
    auto& logger = Logger::getInstance(std::string(LOG_DIR) + "/task05.log");
    logger.setLevel(Logger::Level::DEBUG);

    {
        TrackedString a("hello");
        TrackedString b("world");

        std::cout << a << " " << b << std::endl;

        std::cout << (a == b) << " "
                  << (a != b) << " "
                  << (a < b)  << std::endl;

        auto c = a + b;
        std::cout << c << std::endl;
    }

    return 0;
}