#include "tracked_string.h"
#include "logger.h"

#include <ostream>
#include <sstream>
#include <string>

// ============================================================
// Статические члены и их геттеры
// ============================================================

int TrackedString::totalCreated_ = 0;
int TrackedString::aliveCount_   = 0;

int TrackedString::totalCreated() { return totalCreated_; }
int TrackedString::aliveCount()   { return aliveCount_; }

// ============================================================
// Конструкторы
// ============================================================

TrackedString::TrackedString()
    : TrackedString(std::string{}) {
    std::ostringstream oss;
    oss << "[default ctor (delegating)] this=" << this
        << " alive=" << aliveCount_;
    Logger::getInstance().log(oss.str(), Logger::Level::INFO);
}

TrackedString::TrackedString(const std::string& s)
    : value_(s), id_(++totalCreated_) {
    ++aliveCount_;
    std::ostringstream oss;
    oss << "[string ctor (target)] id=" << id_
        << " this=" << this
        << " value=\"" << value_ << "\""
        << " alive=" << aliveCount_;
    Logger::getInstance().log(oss.str(), Logger::Level::INFO);
}

TrackedString::TrackedString(const char* s)
    : TrackedString(std::string(s)) {
    std::ostringstream oss;
    oss << "[cstr ctor (delegating)] id=" << id_
        << " this=" << this
        << " alive=" << aliveCount_;
    Logger::getInstance().log(oss.str(), Logger::Level::INFO);
}

TrackedString::TrackedString(const TrackedString& other)
    : value_(other.value_), id_(++totalCreated_) {
    ++aliveCount_;
    std::ostringstream oss;
    oss << "[copy ctor] id=" << id_
        << " this=" << this
        << " from id=" << other.id_
        << " alive=" << aliveCount_;
    Logger::getInstance().log(oss.str(), Logger::Level::INFO);
}

// ============================================================
// Оператор присваивания
// ============================================================

TrackedString& TrackedString::operator=(const TrackedString& other) {
    if (this == &other) return *this;

    value_ = other.value_;
    std::ostringstream oss;
    oss << "[copy assign] id=" << id_
        << " this=" << this
        << " from id=" << other.id_;
    Logger::getInstance().log(oss.str(), Logger::Level::INFO);

    return *this;
}

// ============================================================
// Деструктор
// ============================================================

TrackedString::~TrackedString() {
    --aliveCount_;
    std::ostringstream oss;
    oss << "[dtor] id=" << id_
        << " this=" << this
        << " alive=" << aliveCount_;
    Logger::getInstance().log(oss.str(), Logger::Level::INFO);
}

// ============================================================
// Перегруженные операторы (свободные функции)
// ============================================================

// Оператор вывода — дружественная функция, работает с приватными полями
std::ostream& operator<<(std::ostream& os, const TrackedString& ts) {
    Logger::getInstance().log(
        "[operator<<] id=" + std::to_string(ts.id_),
        Logger::Level::INFO);
    os << ts.value_;
    return os;
}

// Операторы сравнения — используют публичные геттеры id() и value()
bool operator==(const TrackedString& a, const TrackedString& b) {
    Logger::getInstance().log(
        "[operator==] id=" + std::to_string(a.id()) +
        " vs id=" + std::to_string(b.id()),
        Logger::Level::INFO);
    return a.value() == b.value();
}

bool operator!=(const TrackedString& a, const TrackedString& b) {
    Logger::getInstance().log(
        "[operator!=] id=" + std::to_string(a.id()) +
        " vs id=" + std::to_string(b.id()),
        Logger::Level::INFO);
    return !(a == b);
}

bool operator<(const TrackedString& a, const TrackedString& b) {
    Logger::getInstance().log(
        "[operator<] id=" + std::to_string(a.id()) +
        " vs id=" + std::to_string(b.id()),
        Logger::Level::INFO);
    return a.value() < b.value();
}

// Оператор сложения — тоже через публичные геттеры
TrackedString operator+(const TrackedString& a, const TrackedString& b) {
    Logger::getInstance().log(
        "[operator+] id=" + std::to_string(a.id()) +
        " + id=" + std::to_string(b.id()),
        Logger::Level::INFO);
    return TrackedString(a.value() + b.value());
}