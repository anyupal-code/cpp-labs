#include "modifiers.h"
#include <iostream>

void modifyByValue(int x) {
    std::cout << "Внутри modifyByValue: адрес x = " << &x
    << ", значение = " << x << "\n";
    x = 999;
    std::cout << "После изменения: x = " << x << "\n";
}

void modifyByPointer(int* x) {
    std::cout << "Внутри modifyByPointer: адрес x = " << x
    << ", значение = " << *x << "\n";
    *x = 999;
    std::cout << "После изменения: *x = " << *x << "\n";
}

void modifyByReference(int& x) {
    std::cout << "Внутри modifyByReference: адрес x = " << &x
    << ", значение = " << x << "\n";
    x = 999;
    std::cout << "После изменения: x = " << x << "\n";
}
