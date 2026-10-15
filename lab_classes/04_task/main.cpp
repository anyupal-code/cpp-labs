#include "tracked_string.h"
#include "logger.h"

#include <string>

int main() {
    auto& logger = Logger::getInstance(std::string(LOG_DIR) + "/task04.log");
    logger.setLevel(Logger::Level::DEBUG);

    TrackedString x;          // делегирующий default → target string
    TrackedString y("test");  // делегирующий cstr    → target string

    return 0;
}