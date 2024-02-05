cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 20)

project(tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tests test_display_work.cpp)
target_include_directories(tests PUBLIC ../)
target_link_libraries(tests mylib gtest gtest_main)