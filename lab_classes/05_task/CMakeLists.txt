set(SOURCES
    main.cpp
    tracked_string.cpp
)

add_executable(05_task ${SOURCES})
target_include_directories(05_task PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(05_task PRIVATE logger)