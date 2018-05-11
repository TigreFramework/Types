cmake_minimum_required(VERSION 3.4)
project(Types)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(FILES Date.cpp Math.cpp)

add_library(tgTypes STATIC ${FILES})

