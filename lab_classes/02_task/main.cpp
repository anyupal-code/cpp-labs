#include "tracked_string.h"
#include "logger.h"

#include <iostream>
#include <string>

int main() {
    auto& logger = Logger::getInstance(std::string(LOG_DIR) + "/task02.log");
    logger.setLevel(Logger::Level::DEBUG);

    {
        TrackedString a;                       // default ctor
        TrackedString b("hello");              // cstr ctor
        std::string s = "world";
        TrackedString c(s);                    // string ctor
        TrackedString d = c;                   // copy ctor
        a = b;                                 // copy assign
    }
    // блок закончился — все объекты уничтожены

    logger.log("totalCreated = " + std::to_string(TrackedString::totalCreated()),
               Logger::Level::INFO);
    logger.log("aliveCount   = " + std::to_string(TrackedString::aliveCount()),
               Logger::Level::INFO);

    return 0;
}