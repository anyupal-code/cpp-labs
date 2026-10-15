#pragma once

#include <iosfwd>
#include <string>

class TrackedString {
public:
    TrackedString();
    TrackedString(const std::string& s);
    TrackedString(const char* s);
    TrackedString(const TrackedString& other);
    TrackedString& operator=(const TrackedString& other);
    ~TrackedString();

    const std::string& value() const { return value_; }
    int id() const { return id_; }

    static int totalCreated();
    static int aliveCount();

private:
    std::string value_;
    int id_;

    static int totalCreated_;
    static int aliveCount_;

    friend std::ostream& operator<<(std::ostream& os, const TrackedString& ts);
};

std::ostream& operator<<(std::ostream& os, const TrackedString& ts);

bool operator==(const TrackedString& a, const TrackedString& b);
bool operator!=(const TrackedString& a, const TrackedString& b);
bool operator< (const TrackedString& a, const TrackedString& b);

TrackedString operator+(const TrackedString& a, const TrackedString& b);