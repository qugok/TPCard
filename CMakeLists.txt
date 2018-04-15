cmake_minimum_required(VERSION 3.9)
project(TPcard)

#set(CMAKE_CXX_STANDARD 11)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
else()
    message(STATUS "Release")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
endif()

aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURSES)

if (WITH_TESTS STREQUAL "1")
    add_subdirectory(tests)
    message(STATUS "Tests Generating done")
endif ()




FIND_PACKAGE(Doxygen)
IF(DOXYGEN_FOUND)
#    EXECUTE_PROCESS(COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile.conf)
    EXECUTE_PROCESS(COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile.conf
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            OUTPUT_FILE ${PROJECT_BINARY_DIR}/log
            ERROR_FILE ${PROJECT_BINARY_DIR}/log)
#    ADD_CUSTOM_TARGET(doc
#            ${DOXYGEN_EXECUTABLE} Doxyfile.conf
#            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
#    MESSAGE(${PROJECT_SOURCE_DIR})
#    MESSAGE(${DOXYGEN_EXECUTABLE})
#    MESSAGE(${PROJECT_BINARY_DIR})
#    ADD_CUSTOM_COMMAND(TARGET docs PRE_BUILD COMMAND doxygen)
#    ADD_CUSTOM_TARGET(f echo arfa)
#    SET(DOXYGEN_INPUT ${CMAKE_SOURCE_DIR})
#    CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/doxygen.conf.in ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
#    CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
#    ADD_CUSTOM_TARGET(doc COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
    MESSAGE(STATUS "Docs Generating done")
ELSE(DOXYGEN_FOUND)
    MESSAGE(STATUS "WARNING: Doxygen not found - Reference manual will not be created")
ENDIF(DOXYGEN_FOUND)

add_executable(TPcard ${SOURSES} main.cpp)

target_include_directories(TPcard PUBLIC ./include)
