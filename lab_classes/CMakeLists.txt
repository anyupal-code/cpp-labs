cmake_minimum_required(VERSION 3.20)
project(LabClasses LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Абсолютный путь к папке logs/ внутри проекта
add_compile_definitions(LOG_DIR="${CMAKE_SOURCE_DIR}/logs")

# Сначала общая библиотека, потом задания
add_subdirectory(common)
add_subdirectory(01_task)
add_subdirectory(02_task)
add_subdirectory(03_task)
add_subdirectory(04_task)
add_subdirectory(05_task)
add_subdirectory(06_task)