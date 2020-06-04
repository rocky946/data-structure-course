cmake_minimum_required(VERSION 3.14)
project(chapter06)

set(CMAKE_CXX_STANDARD 14)

add_executable(6_1 6_1.cpp)
add_executable(tuples tuples.h tuples.cpp test_tuples.cpp)
add_executable(test_g_list g_list.h g_list.cpp test_g_list.cpp)
add_executable(6_3 g_list.h g_list.cpp 6_3.cpp)