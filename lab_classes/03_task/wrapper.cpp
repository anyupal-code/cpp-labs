#include "wrapper.h"

// Вариант A: без списка инициализации.
// Поле str сначала конструируется по умолчанию,
// затем в теле конструктора ему ПРИСВАИВАЕТСЯ новое значение.
WrapperA::WrapperA(const std::string& s) {
    str = TrackedString(s);
}

// Вариант B: со списком инициализации.
// Поле str сразу конструируется нужным значением.
WrapperB::WrapperB(const std::string& s) : str(s) {}