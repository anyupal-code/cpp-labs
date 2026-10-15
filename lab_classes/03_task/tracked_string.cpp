#include "tracked_string.h"
#include "logger.h"

#include <sstream>

int TrackedString::totalCreated_ = 0;
int TrackedString::aliveCount_   = 0;

int TrackedString::totalCreated() { return totalCreated_; }
int TrackedString::aliveCount()   { return aliveCount_; }

TrackedString::TrackedString()
    : value_(), id_(++totalCreated_) {
    ++aliveCount_;
    std::ostringstream oss;
    oss << "[default ctor] id=" << id_
        << " this=" << this
        << " alive=" << aliveCount_;
    Logger::getInstance().log(oss.str(), Logger::Level::INFO);
}

TrackedString::TrackedString(const std::string& s)
    : value_(s), id_(++totalCreated_) {
    ++aliveCount_;
    std::ostringstream oss;
    oss << "[string ctor] id=" << id_
        << " this=" << this
        << " value=\"" << value_ << "\""
        << " alive=" << aliveCount_;
    Logger::getInstance().log(oss.str(), Logger::Level::INFO);
}

TrackedString::TrackedString(const char* s)
    : value_(s), id_(++totalCreated_) {
    ++aliveCount_;
    std::ostringstream oss;
    oss << "[cstr ctor] id=" << id_
        << " this=" << this
        << " value=\"" << value_ << "\""
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

TrackedString& TrackedString::operator=(const TrackedString& other) {
    if (this == &other) return *this;

    value_ = other.value_;
    // id_ не меняется — это id текущего объекта
    std::ostringstream oss;
    oss << "[copy assign] id=" << id_
        << " this=" << this
        << " from id=" << other.id_;
    Logger::getInstance().log(oss.str(), Logger::Level::INFO);

    return *this;
}

TrackedString::~TrackedString() {
    --aliveCount_;
    std::ostringstream oss;
    oss << "[dtor] id=" << id_
        << " this=" << this
        << " alive=" << aliveCount_;
    Logger::getInstance().log(oss.str(), Logger::Level::INFO);
}