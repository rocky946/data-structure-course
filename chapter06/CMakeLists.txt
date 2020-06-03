cmake_minimum_required(VERSION 3.14)
project(chapter06)

set(CMAKE_CXX_STANDARD 14)

add_executable(6_1 6_1.cpp)
add_executable(tuples tuples.h tuples.cpp test_tuples.cpp)