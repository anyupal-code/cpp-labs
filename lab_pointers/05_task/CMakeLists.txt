set(SOURCES main.cpp matrix_utils.cpp)
add_executable(05_task ${SOURCES})
target_include_directories(05_task PRIVATE .)

target_compile_options(05_task PRIVATE -fsanitize=address -g)
target_link_options(05_task PRIVATE -fsanitize=address)

