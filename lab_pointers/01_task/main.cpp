#include "modifiers.h"
#include <iostream>

void demonstrateBasicDifferences() {
    int a = 10;

    std::cout << "До вызова: a = " << a << ", адрес a: " << &a << "\n";
    modifyByValue(a);
    std::cout << "После modifyByValue: a = " << a << "\n\n";

    std::cout << "До вызова: a = " << a << ", адрес a: " << &a << "\n";
    modifyByPointer(&a);
    std::cout << "После modifyByPointer: a = " << a << "\n\n";

    std::cout << "До вызова: a = " << a << ", адрес a: " << &a << "\n";
    modifyByReference(a);
    std::cout << "После modifyByReference: a = " << a << "\n";
}

int main() {
    demonstrateBasicDifferences();
    return 0;
}
