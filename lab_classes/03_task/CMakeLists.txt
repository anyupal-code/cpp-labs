set(SOURCES
    main.cpp
    wrapper.cpp
    tracked_string.cpp
)

add_executable(03_task ${SOURCES})
target_include_directories(03_task PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(03_task PRIVATE logger)