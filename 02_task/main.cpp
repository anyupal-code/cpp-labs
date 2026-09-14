#include <iostream>
#include <cstdint>
#include <limits>

// Печатает 32-битное представление числа от старшего бита к младшему.
// Группирует биты по 8 для читаемости.
void print_bits(uint32_t value) {
    for (int i = 31; i >= 0; --i) {
        uint32_t bit = (value >> i) & 1U;
        std::cout << bit;

        if (i % 8 == 0 && i != 0) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';
}

int main() {
    // ===== Часть 1: беззнаковое переполнение =====
    std::cout << "===== uint32_t overflow =====\n";

    uint32_t umax = std::numeric_limits<uint32_t>::max();  // 0xFFFFFFFF
    std::cout << "UINT32_MAX       = " << umax << "\n";
    std::cout << "UINT32_MAX bits:   ";
    print_bits(umax);

    uint32_t uresult = umax + 2U;  // беззнаковое переполнение — определено стандартом
    std::cout << "\nUINT32_MAX + 2   = " << uresult << "\n";
    std::cout << "result bits:       ";
    print_bits(uresult);

    // ===== Часть 2: знаковое переполнение =====
    std::cout << "\n===== int32_t overflow =====\n";

    int32_t imax = std::numeric_limits<int32_t>::max();  // 0x7FFFFFFF
    std::cout << "INT32_MAX        = " << imax << "\n";
    std::cout << "INT32_MAX bits:    ";
    print_bits(static_cast<uint32_t>(imax));

    // Чтобы не провоцировать UB в самом выражении, делаем вычисление
    // в беззнаковом типе, а потом интерпретируем результат как int32_t.
    int32_t iresult = static_cast<int32_t>(
        static_cast<uint32_t>(imax) + 2U
    );
    std::cout << "\nINT32_MAX + 2    = " << iresult << "\n";
    std::cout << "result bits:       ";
    print_bits(static_cast<uint32_t>(iresult));

    return 0;
}