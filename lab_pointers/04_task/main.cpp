#include "array_utils.h"
#include <iostream>

int main() {
    int* data = new int[3]{1, 2, 3};
    int size = 3;

    std::cout << "Изначально: data = " << data
              << ", size = " << size << "\n";
    for (int i = 0; i < size; ++i) std::cout << data[i] << " ";
    std::cout << "\n\n";

    // 3. Изменяем элементы
    modifyElementsOnly(data, size);
    std::cout << "После modifyElementsOnly: data = " << data << "\n";
    for (int i = 0; i < size; ++i) std::cout << data[i] << " ";
    std::cout << "\n\n";

    // 4. fakeByValue — указатель снаружи не меняется
    fakeByValue(data, size);
    std::cout << "После fakeByValue: data = " << data
              << " (не изменился!)\n\n";

    // 5. Перевыделение
    reallocateArray(data, size);
    std::cout << "После reallocateArray: data = " << data
              << ", size = " << size << "\n";
    for (int i = 0; i < size; ++i) std::cout << data[i] << " ";
    std::cout << "\n";

    // 7. Освобождаем
    delete[] data;
    data = nullptr;

    return 0;
}