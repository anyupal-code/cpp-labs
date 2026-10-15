#pragma once

#include "tracked_string.h"
#include <string>

class WrapperA {
public:
    explicit WrapperA(const std::string& s);

private:
    TrackedString str;
};

class WrapperB {
public:
    explicit WrapperB(const std::string& s);

private:
    TrackedString str;
};