#include <iostream>
#include <cstdint>
#include <cstring>      // memcpy
#include <iomanip>      // setprecision
#include <cmath>        // std::fabs

// ---------------------------------------------------------------------------
// Вспомогательные функции
// ---------------------------------------------------------------------------

// Печатает 32 бита значения от старшего к младшему (группы по 8).
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

// Возвращает 32-битное представление float (безопасно через memcpy).
uint32_t float_to_bits(float f) {
    uint32_t bits = 0;
    std::memcpy(&bits, &f, sizeof(bits));
    return bits;
}

// Печатает разбор float по полям IEEE 754: знак, порядок, мантисса.
void print_float_fields(float f) {
    uint32_t bits = float_to_bits(f);
    uint32_t sign     = (bits >> 31) & 0x1U;
    uint32_t exponent = (bits >> 23) & 0xFFU;
    uint32_t mantissa = bits & 0x7FFFFFU;

    std::cout << "  value        = " << f << "\n";
    std::cout << "  bits         = ";
    print_bits(bits);
    std::cout << "  sign         = " << sign << "\n";
    std::cout << "  exponent     = " << exponent
              << " (biased), " << static_cast<int>(exponent) - 127
              << " (unbiased)\n";
    std::cout << "  mantissa     = " << mantissa << " (0x"
              << std::hex << mantissa << std::dec << ")\n";
}

// ---------------------------------------------------------------------------
// Часть 1. Представление чисел
// ---------------------------------------------------------------------------

void part1_representation() {
    std::cout << "===== Part 1: IEEE 754 representation =====\n\n";

    std::cout << "--- 10.25 ---\n";
    float f1 = 10.25f;
    print_float_fields(f1);

    std::cout << "\n--- 7.1 ---\n";
    float f2 = 7.1f;
    print_float_fields(f2);

    std::cout << "\n--- 10.25 + 7.1 (setprecision 12) ---\n";
    float sum = f1 + f2;
    std::cout << std::setprecision(12);
    std::cout << "  sum = " << sum << "\n";
    std::cout << "  expected (exact) = 17.35\n";
    std::cout << std::setprecision(6);   // вернуть дефолт для дальнейших выводов
}

// ---------------------------------------------------------------------------
// Часть 2. Нарушение ассоциативности
// ---------------------------------------------------------------------------

void part2_associativity() {
    std::cout << "\n===== Part 2: associativity violation =====\n";

    float a = 1.0e20f;
    float b = -1.0e20f;
    float c = 1.0f;

    float r1 = (a + b) + c;   // (1e20 - 1e20) + 1 = 0 + 1 = 1
    float r2 = a + (b + c);   // 1e20 + (-1e20 + 1) ≈ 1e20 + (-1e20) = 0

    std::cout << std::setprecision(12);
    std::cout << "  a = " << a << ", b = " << b << ", c = " << c << "\n";
    std::cout << "  (a + b) + c = " << r1 << "\n";
    std::cout << "  a + (b + c) = " << r2 << "\n";
    std::cout << "  equal? " << (r1 == r2 ? "yes" : "no") << "\n";
    std::cout << std::setprecision(6);
}

// ---------------------------------------------------------------------------
// Часть 3. Сравнение на равенство
// ---------------------------------------------------------------------------

void part3_equality() {
    std::cout << "\n===== Part 3: equality comparison =====\n";

    float x = 0.1f + 0.2f;
    float y = 0.3f;

    std::cout << std::setprecision(12);
    std::cout << "  x = 0.1f + 0.2f = " << x << "\n";
    std::cout << "  y = 0.3f        = " << y << "\n";
    std::cout << "  x == y ?        " << (x == y ? "true" : "false") << "\n";

    // Правильное сравнение — через эпсилон
    const float eps = 1e-6f;
    bool nearly_equal = std::fabs(x - y) < eps;
    std::cout << "  |x - y| = " << std::fabs(x - y) << "\n";
    std::cout << "  |x - y| < 1e-6 ? " << (nearly_equal ? "true" : "false") << "\n";
    std::cout << std::setprecision(6);
}

// ---------------------------------------------------------------------------

int main() {
    part1_representation();
    part2_associativity();
    part3_equality();
    return 0;
}