cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 20)
project(longnumlib)

set(Headers
        LongNum.hpp
)
set(Sources
        LongNum.cpp
)
# only one header and one source in lib (

add_library(mylib STATIC ${Sources} ${Headers})
