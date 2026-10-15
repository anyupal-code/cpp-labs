set(SOURCES main.cpp)

add_executable(01_task ${SOURCES})
target_include_directories(01_task PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Подключаем общий логгер
target_link_libraries(01_task PRIVATE logger)