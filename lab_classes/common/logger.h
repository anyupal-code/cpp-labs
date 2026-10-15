#pragma once

#include <fstream>
#include <string>

class Logger {
public:
    struct Level {
        static const int ERROR   = 0;
        static const int WARNING = 1;
        static const int INFO    = 2;
        static const int DEBUG   = 3;
    };

    static Logger& getInstance(const std::string& filename = "default.log");

    void log(const std::string& message, int level);
    void setLevel(int level);
    void setFile(const std::string& filename);

    Logger(const Logger&)            = delete;
    Logger& operator=(const Logger&) = delete;

    ~Logger();

private:
    Logger(const std::string& filename);

    std::ofstream file;
    int currentLevel;
};