#include <iostream>
#include <iomanip>
#include <chrono>

// ---------------------------------------------------------------------------
// Замер с volatile: каждое += 1 — чтение/запись в память.
// Компилятор не может оптимизировать цикл.
// ---------------------------------------------------------------------------
template <typename T>
double measure_volatile(size_t N, T addend) {
    volatile T x = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < N; ++i) {
        x += addend;
    }
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double, std::micro>(end - start).count();
}

// ---------------------------------------------------------------------------
// Замер без volatile: компилятор может сильно оптимизировать.
// Чтобы цикл не «испарился», после цикла обращаемся к x через
// непредсказуемое условие (компилятор не знает, истинно ли оно).
// ---------------------------------------------------------------------------
template <typename T>
double measure_plain(size_t N, T addend) {
    T x = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < N; ++i) {
        x += addend;
    }
    auto end = std::chrono::high_resolution_clock::now();

    // «Используем» x, чтобы компилятор не выкинул цикл.
    // Условие почти никогда не истинно, но компилятор этого не знает.
    if (x == static_cast<T>(-123)) {
        std::cout << "";
    }

    return std::chrono::duration<double, std::micro>(end - start).count();
}

// ---------------------------------------------------------------------------
// Печать одной строки таблицы.
// Русский текст идёт как есть, числа выравниваются через setw.
// ---------------------------------------------------------------------------
void print_row(const char* name, size_t size, double time_us) {
    std::cout << std::left  << std::setw(18) << name
              << std::right << std::setw(14) << size
              << std::setw(18) << time_us << "\n";
}

int main() {
    const size_t N = 100'000'000;   // 10^8

    std::cout << std::fixed << std::setprecision(1);

    // =======================================================================
    // Таблица 1. С volatile
    // =======================================================================
    std::cout << "===== С volatile =====\n";
    std::cout << std::left  << std::setw(18) << "Тип"
              << std::right << std::setw(14) << "Размер (байт)"
              << std::setw(18) << "Время (µs)" << "\n";
    std::cout << std::string(50, '-') << "\n";

    print_row("char",           sizeof(char),           measure_volatile<char>          (N, static_cast<char>(1)));
    print_row("short",          sizeof(short),          measure_volatile<short>         (N, static_cast<short>(1)));
    print_row("int",            sizeof(int),            measure_volatile<int>           (N, 1));
    print_row("unsigned char",  sizeof(unsigned char),  measure_volatile<unsigned char> (N, static_cast<unsigned char>(1)));
    print_row("unsigned short", sizeof(unsigned short), measure_volatile<unsigned short>(N, static_cast<unsigned short>(1)));
    print_row("unsigned int",   sizeof(unsigned int),   measure_volatile<unsigned int>  (N, 1U));
    print_row("float",          sizeof(float),          measure_volatile<float>         (N, 1.0f));
    print_row("double",         sizeof(double),         measure_volatile<double>        (N, 1.0));

    // =======================================================================
    // Таблица 2. Без volatile
    // =======================================================================
    std::cout << "\n===== Без volatile =====\n";
    std::cout << std::left  << std::setw(18) << "Тип"
              << std::right << std::setw(14) << "Размер (байт)"
              << std::setw(18) << "Время (µs)" << "\n";
    std::cout << std::string(50, '-') << "\n";

    print_row("char",           sizeof(char),           measure_plain<char>          (N, static_cast<char>(1)));
    print_row("short",          sizeof(short),          measure_plain<short>         (N, static_cast<short>(1)));
    print_row("int",            sizeof(int),            measure_plain<int>           (N, 1));
    print_row("unsigned char",  sizeof(unsigned char),  measure_plain<unsigned char> (N, static_cast<unsigned char>(1)));
    print_row("unsigned short", sizeof(unsigned short), measure_plain<unsigned short>(N, static_cast<unsigned short>(1)));
    print_row("unsigned int",   sizeof(unsigned int),   measure_plain<unsigned int>  (N, 1U));
    print_row("float",          sizeof(float),          measure_plain<float>         (N, 1.0f));
    print_row("double",         sizeof(double),         measure_plain<double>        (N, 1.0));

    return 0;
}