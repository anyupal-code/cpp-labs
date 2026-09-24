#include "array_utils.h"
#include <iostream>

int main() {
    const int SIZE = 5;

    // 1. Статический массив
    int staticArr[SIZE];

    // 2. Динамический массив
    int* dynamicArr = new int[SIZE];

    // 3. Заполнение
    fillArray(staticArr, SIZE);
    fillArray(dynamicArr, SIZE);

    // 4. Вывод таблиц
    std::cout << "=== Статический массив ===\n";
    printArrayInfo(staticArr, SIZE);

    std::cout << "\n=== Динамический массив ===\n";
    printArrayInfo(dynamicArr, SIZE);

    // 5. Размеры
    std::cout << "\nsizeof(staticArr)   = " << sizeof(staticArr)   << " байт\n";
    std::cout << "sizeof(dynamicArr)  = " << sizeof(dynamicArr)  << " байт\n";

    // 6. Освобождение памяти
    delete[] dynamicArr;
    dynamicArr = nullptr;

    return 0;
}