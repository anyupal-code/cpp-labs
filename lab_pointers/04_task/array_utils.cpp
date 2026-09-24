#include "array_utils.h"
#include <iostream>

void modifyElementsOnly(int* arr, int size) {
    std::cout << "[modifyElementsOnly] адрес arr: " << arr << "\n";
    for (int i = 0; i < size; ++i) {
        arr[i] *= 10;
    }
}

void reallocateArray(int*& arr, int& size) {
    std::cout << "[reallocateArray] старый arr: " << arr
              << ", size = " << size << "\n";

    delete[] arr;                    // освобождаем старую память

    int newSize = size * 2;
    arr = new int[newSize];          // выделяем новую
    for (int i = 0; i < newSize; ++i) {
        arr[i] = i + 1;
    }
    size = newSize;

    std::cout << "[reallocateArray] новый arr: " << arr
              << ", size = " << size << "\n";
}

void fakeByValue(int* arr, int size) {
    std::cout << "[fakeByValue] адрес arr внутри: " << arr << "\n";
    arr = nullptr;                   // меняется только локальная копия
    std::cout << "[fakeByValue] после arr = nullptr: " << arr << "\n";
}