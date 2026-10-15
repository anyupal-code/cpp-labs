#include "wrapper.h"
#include "logger.h"

#include <string>

int main() {
    auto& logger = Logger::getInstance(std::string(LOG_DIR) + "/task03_a.log");
    logger.setLevel(Logger::Level::DEBUG);

    {
        WrapperA w("hello");
    }

    logger.setFile(std::string(LOG_DIR) + "/task03_b.log");
    logger.setLevel(Logger::Level::DEBUG);

    {
        WrapperB w("hello");
    }

    return 0;
}