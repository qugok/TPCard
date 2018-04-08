cmake_minimum_required(VERSION 3.9)

#set(gtest_SOURCE_DIR C:/Users/iesek/CLionProjects/googletest/googletest)

#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(
        C:/Users/iesek/CLionProjects/googletest/googletest
        ${CMAKE_CURRENT_BINARY_DIR}/gtest)


#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/.. ${CMAKE_CURRENT_BINARY_DIR})

#file(SOURCES GRUB ./tests/*.cpp)

include_directories(./../include)
#
aux_source_directory(./../src SOURSES)

#add_executable(runBasicTests tests.cpp main.cpp)

add_executable(runBasicTests tests.cpp main.cpp ${SOURSES})

#target_link_libraries(runBasicTests gtest ${SOURSES})

target_link_libraries(runBasicTests gtest)
