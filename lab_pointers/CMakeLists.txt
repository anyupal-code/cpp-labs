cmake_minimum_required(VERSION 3.10)
project(LabPointers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Подключаем каждое задание как поддиректорию
add_subdirectory(01_task)
add_subdirectory(02_task)
add_subdirectory(03_task)
add_subdirectory(04_task)
add_subdirectory(05_task)
