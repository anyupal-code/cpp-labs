#include "array_utils.h"
#include <iostream>
#include <cstdint>

void fillArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = (i + 1) * 7;
    }
}

void printArrayInfo(const int* arr, int size) {
    std::cout << "i | Значение | &arr[i] | (arr + i) | Разница\n";
    std::cout << "--|----------|---------|-----------|--------\n";

    for (int i = 0; i < size; ++i) {
        const void* addr1 = static_cast<const void*>(&arr[i]);
        const void* addr2 = static_cast<const void*>(arr + i);

        std::cout << i << " | "
                  << arr[i] << " | "
                  << addr1 << " | "
                  << addr2 << " | ";

        if (i == 0) {
            std::cout << "—\n";
        } else {
            auto diff = reinterpret_cast<const char*>(&arr[i])
                      - reinterpret_cast<const char*>(&arr[i - 1]);
            std::cout << diff << "\n";
        }
    }
}