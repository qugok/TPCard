cmake_minimum_required(VERSION 3.9)
project(TPcard)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURSES)

if (WITH_TESTS STREQUAL "1")
    message("generating tests")
    add_subdirectory(tests)
endif ()


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("debug\nwith logging and debug info")
    # добавить этот функцинал)
    # научиться передавать константы в код
endif ()

add_executable(TPcard ${SOURSES} main.cpp)

target_include_directories(TPcard PUBLIC ./include)
