#include "logger.h"

#include <chrono>
#include <filesystem>
#include <format>
#include <iostream>

Logger::Logger(const std::string& filename)
    : currentLevel(Level::DEBUG) {

    std::filesystem::create_directories(
        std::filesystem::path(filename).parent_path());

    file.open(filename, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл лога: " << filename << "\n";
    }
}

Logger::~Logger() {
    if (file.is_open()) {
        file.close();
    }
}

Logger& Logger::getInstance(const std::string& filename) {
    static Logger instance(filename);
    return instance;
}

void Logger::log(const std::string& message, int level) {
    if (level > currentLevel) {
        return;
    }

    auto now = std::chrono::floor<std::chrono::seconds>(
        std::chrono::system_clock::now());
    std::string time = std::format("{:%Y-%m-%d %H:%M:%S}", now);

    std::string levelStr;
    switch (level) {
        case Level::ERROR:   levelStr = "ERROR";   break;
        case Level::WARNING: levelStr = "WARNING"; break;
        case Level::INFO:    levelStr = "INFO";    break;
        case Level::DEBUG:   levelStr = "DEBUG";   break;
        default:             levelStr = "UNKNOWN"; break;
    }

    file << "[" << time << "] [" << levelStr << "] " << message << "\n";
    file.flush();
}

void Logger::setLevel(int level) {
    currentLevel = level;
}

void Logger::setFile(const std::string& filename) {
    if (file.is_open()) {
        file.close();
    }

    std::filesystem::create_directories(
        std::filesystem::path(filename).parent_path());

    file.open(filename, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл лога: " << filename << "\n";
    }
}