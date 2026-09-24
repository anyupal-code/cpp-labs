#include <iostream>
#include <cstdint>

// Печатает 32-битное представление числа от старшего бита к младшему.
// Группирует биты по 8 для читаемости.
void print_bits(uint32_t value) {
    for (int i = 31; i >= 0; --i) {
        uint32_t bit = (value >> i) & 1U;
        std::cout << bit;

        // Пробел после каждых 8 бит, кроме последнего
        if (i % 8 == 0 && i != 0) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';
}

int main() {
    // ===== Часть 1: представление +42 =====
    uint32_t a = 42;
    std::cout << "a = 42\n";
    std::cout << "a in binary: ";
    print_bits(a);

    // ===== Часть 2: битовые операции =====
    uint32_t b = static_cast<uint32_t>(-17);
    std::cout << "\nb = -17\n";
    std::cout << "b in binary: ";
    print_bits(b);

    // a & b
    std::cout << "\na & b  = " << (a & b) << "\n";
    std::cout << "        ";
    print_bits(a & b);

    // a | b
    std::cout << "\na | b  = " << (a | b) << "\n";
    std::cout << "        ";
    print_bits(a | b);

    // a ^ b
    std::cout << "\na ^ b  = " << (a ^ b) << "\n";
    std::cout << "        ";
    print_bits(a ^ b);

    // ~a
    std::cout << "\n~a     = " << (~a) << "\n";
    std::cout << "        ";
    print_bits(~a);

    // a << 2
    std::cout << "\na << 2 = " << (a << 2) << "\n";
    std::cout << "        ";
    print_bits(a << 2);

    // a >> 2
    std::cout << "\na >> 2 = " << (a >> 2) << "\n";
    std::cout << "        ";
    print_bits(a >> 2);

    // b << 2
    std::cout << "\nb << 2 = " << (b << 2) << "\n";
    std::cout << "        ";
    print_bits(b << 2);

    // b >> 2
    std::cout << "\nb >> 2 = " << (b >> 2) << "\n";
    std::cout << "        ";
    print_bits(b >> 2);

    return 0;
}