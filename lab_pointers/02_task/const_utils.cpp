#include "const_utils.h"
#include <iostream>

void printValue(const int* ptr) {
    std::cout << "printValue: " << *ptr << "\n";
}

void printValueRef(const int& value) {
    std::cout << "printValueRef: " << value << "\n";
}

void tryModify(const int* ptr) {
    // *ptr = 999; // ОШИБКА: нельзя менять данные через const int*
    std::cout << "tryModify: значение менять нельзя, только читать: " << *ptr << "\n";
}

void setValue(int* ptr, int newValue) {
    *ptr = newValue;
}