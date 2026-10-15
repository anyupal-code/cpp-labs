#include "logger.h"

#include <cstdint>
#include <iostream>
#include <string>

int main() {
    auto& logger = Logger::getInstance(std::string(LOG_DIR) + "/task01.log");
    logger.setLevel(Logger::Level::DEBUG);

    logger.log("ERROR message",   Logger::Level::ERROR);
    logger.log("WARNING message", Logger::Level::WARNING);
    logger.log("INFO message",    Logger::Level::INFO);
    logger.log("DEBUG message",   Logger::Level::DEBUG);

    logger.setLevel(Logger::Level::WARNING);
    logger.log("ERROR после setLevel(WARNING)",   Logger::Level::ERROR);
    logger.log("WARNING после setLevel(WARNING)", Logger::Level::WARNING);
    logger.log("INFO после setLevel(WARNING) — не попадёт в лог",  Logger::Level::INFO);
    logger.log("DEBUG после setLevel(WARNING) — не попадёт в лог", Logger::Level::DEBUG);

    // Возвращаем уровень, чтобы сообщения ниже попали в лог
    logger.setLevel(Logger::Level::INFO);

    auto& logger2 = Logger::getInstance();
    logger.log("Проверка Singleton: адрес logger  = " +
               std::to_string(reinterpret_cast<std::uintptr_t>(&logger)),
               Logger::Level::INFO);
    logger.log("Проверка Singleton: адрес logger2 = " +
               std::to_string(reinterpret_cast<std::uintptr_t>(&logger2)),
               Logger::Level::INFO);

    logger.setFile(std::string(LOG_DIR) + "/task01_second.log");
    logger.setLevel(Logger::Level::INFO);
    logger.log("Сообщение во второй файл", Logger::Level::INFO);

    return 0;
}