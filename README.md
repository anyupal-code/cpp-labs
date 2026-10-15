# C++ Labs

Учебные лабораторные работы по курсу «Программирование на C++».

## Список работ

| № | Папка | Тема |
|---|-------|------|
| 1 | [`lab_datatypes`](./lab_datatypes) | Исследование типов данных. Битовые vs арифметические операции |
| 2 | [`lab_pointers`](./lab_pointers)   | Динамические массивы, указатели и функции |
| 3 | [`lab_classes`](./lab_classes)     | ООП: конструкторы, операторы, Singleton, push_back vs emplace_back |

## Структура

Каждая лабораторная работа — **отдельный CMake-проект** в своей папке. Внутри каждой работы — задания по подпапкам.

```
cpp-labs/
├── README.md                       ← этот файл
├── .gitignore
├── lab_datatypes/                  ← лабораторная 1
│   ├── CMakeLists.txt
│   ├── 01_task/
│   ├── 02_task/
│   ├── 03_task/
│   ├── 04_task/
│   └── 05_task/
├── lab_pointers/                   ← лабораторная 2
│   ├── CMakeLists.txt
│   ├── 01_task/
│   ├── 02_task/
│   ├── 03_task/
│   ├── 04_task/
│   └── 05_task/
└── lab_classes/                    ← лабораторная 3
    ├── CMakeLists.txt
    ├── common/                     ← общая библиотека logger (Singleton)
    ├── 01_task/
    ├── 02_task/
    ├── 03_task/
    ├── 04_task/
    ├── 05_task/
    ├── 06_task/
    └── logs/
```

В каждой папке `NN_task/` лежат:
- `main.cpp` — самодостаточная программа (все данные через параметры, без глобальных переменных),
- `CMakeLists.txt` — сборка отдельного исполняемого файла,
- `<utils>.h` / `<utils>.cpp` — модульный код задания (там, где требуется),
- `README.md` — ответы на контрольные вопросы и выводы по заданию.

## Требования

- CMake ≥ 3.10 (для `lab_classes` — ≥ 3.20)
- Компилятор C++ с поддержкой **C++23** (GCC 13+, Clang 16+)
- IDE: CLion, VS Code + CMake Tools — на выбор

## Сборка конкретной лабораторной работы

Зайти в папку работы и собрать, например в Release:

```bash
cd lab_datatypes
cmake -S . -B cmake-build-release -DCMAKE_BUILD_TYPE=Release
cmake --build cmake-build-release
```

Исполняемые файлы появятся в `cmake-build-release/NN_task/taskNN`.

## Запуск отдельного задания

```bash
cmake --build cmake-build-release --target task04
./cmake-build-release/04_task/task04
```

## Примечания

- Каждая работа **независима**: запуск одного задания не зависит от других папок.
- Папки сборки (`cmake-build-*`) в репозиторий не попадают (см. `.gitignore`).
- В `lab_classes` папка `logs/` **не игнорируется** — в README заданий приводятся фрагменты логов.