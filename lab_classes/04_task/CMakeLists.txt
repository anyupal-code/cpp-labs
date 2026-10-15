set(SOURCES
    main.cpp
    tracked_string.cpp
)

add_executable(04_task ${SOURCES})
target_include_directories(04_task PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(04_task PRIVATE logger)