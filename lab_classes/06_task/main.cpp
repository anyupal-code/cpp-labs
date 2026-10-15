#include "tracked_string.h"
#include "logger.h"

#include <string>
#include <vector>

int main() {
    // ---- Эксперимент 1: без reserve ----
    {
        auto& logger = Logger::getInstance(std::string(LOG_DIR) + "/task06_no_reserve.log");
        logger.setLevel(Logger::Level::DEBUG);

        std::vector<TrackedString> vec;

        logger.log("--- push_back(TrackedString(\"temp\")) ---", Logger::Level::INFO);
        vec.push_back(TrackedString("temp"));

        logger.log("--- TrackedString ts(\"str\"); push_back(ts) ---", Logger::Level::INFO);
        TrackedString ts("str");
        vec.push_back(ts);

        logger.log("--- emplace_back(\"temp\") ---", Logger::Level::INFO);
        vec.emplace_back("temp");

        logger.log("--- emplace_back(TrackedString(\"temp\")) ---", Logger::Level::INFO);
        vec.emplace_back(TrackedString("temp"));
    }

    // ---- Эксперимент 2: с reserve ----
    {
        auto& logger = Logger::getInstance();
        logger.setFile(std::string(LOG_DIR) + "/task06_reserve.log");
        logger.setLevel(Logger::Level::DEBUG);

        std::vector<TrackedString> vec;
        vec.reserve(10);

        logger.log("--- push_back(TrackedString(\"temp\")) ---", Logger::Level::INFO);
        vec.push_back(TrackedString("temp"));

        logger.log("--- TrackedString ts(\"str\"); push_back(ts) ---", Logger::Level::INFO);
        TrackedString ts("str");
        vec.push_back(ts);

        logger.log("--- emplace_back(\"temp\") ---", Logger::Level::INFO);
        vec.emplace_back("temp");

        logger.log("--- emplace_back(TrackedString(\"temp\")) ---", Logger::Level::INFO);
        vec.emplace_back(TrackedString("temp"));
    }

    return 0;
}