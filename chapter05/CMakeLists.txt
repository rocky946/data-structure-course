cmake_minimum_required(VERSION 3.14)
project(chapter05)

set(CMAKE_CXX_STANDARD 14)

add_executable(fib1 fib1.cpp)
add_executable(fib2 fib2.cpp)
add_executable(hanoi1 hanoi1.cpp)
add_executable(hannoi2 sq_stack.h sq_stack.cpp hanoi2.cpp)

add_executable(5_2 5_2.cpp)
add_executable(5_3 array_list.h array_list.cpp 5_3.cpp)
add_executable(5_4 linked_list.h linked_list.cpp 5_4.cpp)