# Лабораторная работа 3. ООП

Лабораторная работа по курсу «Программирование на C++». Посвящена
изучению поведения конструкторов, деструкторов и операторов класса,
спискам инициализации, делегирующим конструкторам, семантике перемещения
и паттерну Singleton.

## Описание

Работа состоит из шести заданий, каждое — в отдельной папке `NN_task/`
и оформлено как самостоятельный исполняемый файл. Общий код (логгер
на основе Singleton) лежит в папке `common/`, собирается как статическая
библиотека `logger` и подключается ко всем заданиям через
`target_link_libraries`.

## Файлы

```
lab_classes/
├── CMakeLists.txt
├── common/                       ← общая библиотека
│   ├── CMakeLists.txt
│   ├── logger.h
│   └── logger.cpp
├── 01_task/                      ← тестирование логгера
├── 02_task/                      ← виды конструкторов TrackedString
├── 03_task/                      ← списки инициализации
├── 04_task/                      ← делегирующие конструкторы
├── 05_task/                      ← перегрузка операторов
├── 06_task/                      ← push_back vs emplace_back
└── logs/                         ← лог-файлы всех заданий
```

В каждой папке `NN_task/`:
- `main.cpp` — точка входа,
- `CMakeLists.txt` — сборка цели,
- `tracked_string.h` / `tracked_string.cpp` (со 02_task) — класс-обёртка
  над `std::string` с логированием,
- `wrapper.h` / `wrapper.cpp` (только в 03_task) — демонстрация списков
  инициализации,
- `README.md` — ответы на вопросы задания.

## Функции

| Задание | Ключевые элементы |
|---|---|
| 01_task | `Logger::getInstance`, `Logger::log`, `setLevel`, `setFile` |
| 02_task | конструкторы `TrackedString`: default, string, cstr, copy; `operator=`; деструктор |
| 03_task | `WrapperA` (без списка инициализации), `WrapperB` (со списком) |
| 04_task | делегирующие конструкторы `TrackedString()` и `TrackedString(const char*)` |
| 05_task | `operator<<`, `operator==`, `operator!=`, `operator<`, `operator+` |
| 06_task | move-конструктор и move-присваивание `TrackedString`, эксперименты с `std::vector` |

## Что нужно сделать

### Задание 1. Логгер на основе Singleton
- Реализовать класс `Logger` в `common/` с приватным конструктором,
  статическим `getInstance()`, методами `log`, `setLevel`, `setFile`.
- Вложенная структура `Level` с `ERROR`, `WARNING`, `INFO`, `DEBUG`.
- Логи писать в `LOG_DIR/task01.log`, `LOG_DIR/task01_second.log`.
- Протестировать фильтрацию по уровню, Singleton, `setFile()`.
- Ответить на 6 вопросов в `01_task/README.md`.

### Задание 2. Виды конструкторов
- Реализовать `TrackedString` с приватным `std::string value_`, полем `id_`,
  статическими счётчиками `totalCreated_` и `aliveCount_`.
- Четыре конструктора (default, string, cstr, copy), `operator=`, деструктор.
- Каждый конструктор / деструктор пишет в лог.
- Ответить на 5 вопросов в `02_task/README.md`.

### Задание 3. Списки инициализации
- Реализовать `WrapperA` (без списка инициализации) и `WrapperB` (со списком).
- Показать разницу в логах `task03_a.log` и `task03_b.log`.
- Ответить на 5 вопросов в `03_task/README.md`.

### Задание 4. Делегирующие конструкторы
- Переделать `TrackedString()` и `TrackedString(const char*)` в делегирующие.
- Счётчики и `id_` обновлять **только** в целевом конструкторе.
- Ответить на 3 вопроса в `04_task/README.md`.

### Задание 5. Перегрузка операторов
- Реализовать `operator<<`, `operator==`, `operator!=`, `operator<`, `operator+`.
- Ответить на 4 вопроса в `05_task/README.md`.

### Задание 6*. push_back vs emplace_back
- Добавить move-конструктор и move-присваивание с `noexcept`.
- Провести два эксперимента с `std::vector`: без `reserve` и с `reserve(10)`.
- Ответить на 5 вопросов в `06_task/README.md`.

## Требования

- CMake ≥ 3.20 (из-за `add_compile_definitions`)
- Компилятор C++ с поддержкой **C++23** (GCC 13+, Clang 16+)

## Сборка

Из корня работы:

```bash
cmake -S . -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build cmake-build-debug
```

Будут собраны шесть исполняемых файлов: `01_task`, `02_task`, `03_task`,
`04_task`, `05_task`, `06_task`.

## Запуск отдельного задания

```bash
cmake --build cmake-build-debug --target 02_task
./cmake-build-debug/02_task/02_task
```

Например, для задания 6:

```bash
cmake --build cmake-build-debug --target 06_task
./cmake-build-debug/06_task/06_task
```

## Примечания

- Общий логгер лежит в `common/` и **не копируется** по заданиям —
  подключается через `target_link_libraries(... PRIVATE logger)`.
- `TrackedString` **копируется** из задания в задание и дорабатывается —
  каждая папка самодостаточна.
- Каждое задание пишет логи в свой файл в `logs/` и не затирает чужие.
- Путь к папке логов передаётся через `LOG_DIR` (определяется
  в корневом `CMakeLists.txt` через `add_compile_definitions`).
- Использование глобальных переменных запрещено. Исключения —
  статический объект `Logger` внутри `getInstance()` и статические
  счётчики `TrackedString`.
- Архив со всей папкой `lab_classes/` (без `cmake-build-*`, но **с** `logs/`)
  загружается в SmartLMS курса.