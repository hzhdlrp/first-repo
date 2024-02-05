cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 20)

project(project1 VERSION 2.1 LANGUAGES C CXX)

add_executable(project1 main.cpp)
add_library(mylib long-number-library/LongNum.cpp long-number-library/LongNum.h)
target_link_libraries(project1 PRIVATE mylib)

