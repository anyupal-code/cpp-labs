#include <iostream>
#include <iomanip>
#include <cstdint>
#include <chrono>

// ---------------------------------------------------------------------------
// Шаблонная функция замера.
//   op      — лямбда, выполняющая одну операцию над x
//   N       — количество итераций
//   initial — исходное значение x, восстанавливаемое каждую итерацию
// ---------------------------------------------------------------------------
template <typename T, typename Op>
double measure(Op op, size_t N, T initial) {
    volatile T x    = initial;   // volatile: запрещаем компилятору оптимизировать
    volatile T sink = 0;         // volatile-«сток», чтобы результат не выкинули

    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < N; ++i) {
        x    = initial;          // восстанавливаем значение, иначе быстро уйдём в 0
        sink = op(x);            // измеряемая операция
    }

    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::micro>(end - start).count();
}

int main() {
    const size_t N = 100'000'000;     // 10^8 итераций

    const int32_t  init_i = 123456789;
    const uint32_t init_u = 123456789U;

    // ---- Лямбды: арифметические аналоги ----
    auto div2   = [](auto x) { return x / 2; };
    auto mul2   = [](auto x) { return x * 2; };
    auto even_m = [](auto x) { return (x % 2 == 0) ? 1 : 0; };

    // ---- Лямбды: битовые аналоги ----
    auto shr1   = [](auto x) { return x >> 1; };
    auto shl1   = [](auto x) { return x << 1; };
    auto even_b = [](auto x) { return ((x & 1) == 0) ? 1 : 0; };

    // =======================================================================
    // Замеры для int32_t
    // =======================================================================
    double i_div    = measure<int32_t>(div2,     N, init_i);
    double i_shr    = measure<int32_t>(shr1,     N, init_i);
    double i_mul    = measure<int32_t>(mul2,     N, init_i);
    double i_shl    = measure<int32_t>(shl1,     N, init_i);
    double i_even_m = measure<int32_t>(even_m,   N, init_i);
    double i_even_b = measure<int32_t>(even_b,   N, init_i);

    // =======================================================================
    // Замеры для uint32_t
    // =======================================================================
    double u_div    = measure<uint32_t>(div2,    N, init_u);
    double u_shr    = measure<uint32_t>(shr1,    N, init_u);
    double u_mul    = measure<uint32_t>(mul2,    N, init_u);
    double u_shl    = measure<uint32_t>(shl1,    N, init_u);
    double u_even_m = measure<uint32_t>(even_m,  N, init_u);
    double u_even_b = measure<uint32_t>(even_b,  N, init_u);

    // =======================================================================
    // Вывод таблицы
    // =======================================================================
    std::cout << std::fixed << std::setprecision(1);

    std::cout << "Тип         Операция             Арифметика (µs)    Битовая (µs)\n";
    std::cout << "------------------------------------------------------------------\n";

    // ---- int32_t ----
    std::cout << "int32_t     Деление на 2        "
              << std::setw(14) << i_div
              << std::setw(18) << i_shr << "\n";

    std::cout << "int32_t     Умножение на 2      "
              << std::setw(14) << i_mul
              << std::setw(18) << i_shl << "\n";

    std::cout << "int32_t     Чётность            "
              << std::setw(14) << i_even_m
              << std::setw(18) << i_even_b << "\n";

    std::cout << "\n";

    // ---- uint32_t ----
    std::cout << "uint32_t    Деление на 2        "
              << std::setw(14) << u_div
              << std::setw(18) << u_shr << "\n";

    std::cout << "uint32_t    Умножение на 2      "
              << std::setw(14) << u_mul
              << std::setw(18) << u_shl << "\n";

    std::cout << "uint32_t    Чётность            "
              << std::setw(14) << u_even_m
              << std::setw(18) << u_even_b << "\n";

    return 0;
}