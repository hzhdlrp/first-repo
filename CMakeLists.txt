cmake_minimum_required(VERSION 3.26)
project(project1)

set(CMAKE_CXX_STANDARD 17)

add_library(longnum SHARED
        LongNum.h
        LongNum.cpp
)

add_executable(project1 main.cpp LongNum.cpp)
target_link_libraries(project1 longnum)
