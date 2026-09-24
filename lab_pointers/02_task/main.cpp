#include "const_utils.h"
#include <iostream>

int main() {
    int x = 42;

    // 2. Чтение через const int* и const int&
    printValue(&x);
    printValueRef(x);

    // 3. Изменение через обычный указатель
    setValue(&x, 100);
    std::cout << "После setValue: x = " << x << "\n";

    // 4. Указатель на константу
    const int* p1 = &x;
    tryModify(p1);
    // *p1 = 50;  // ОШИБКА компиляции: через const int* менять нельзя

    // 5. Константный указатель
    int y = 200;
    int* const p2 = &y;
    // p2 = &x;   // ОШИБКА компиляции: нельзя переприсвоить константный указатель
    *p2 = 300;    // ОК: данные менять можно
    std::cout << "После *p2 = 300: y = " << y << "\n";

    return 0;
}