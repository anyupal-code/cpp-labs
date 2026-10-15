set(SOURCES
    main.cpp
    tracked_string.cpp
)

add_executable(06_task ${SOURCES})
target_include_directories(06_task PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(06_task PRIVATE logger)