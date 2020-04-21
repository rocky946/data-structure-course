cmake_minimum_required(VERSION 3.14)
project(chapter03)

set(CMAKE_CXX_STANDARD 14)

# 顺序栈
add_executable(main main.cpp)
add_executable(sq_stack sq_stack.h sq_stack.cpp test_sq_stack.cpp)
add_executable(3_4 sq_stack.h sq_stack.cpp 3_4.cpp)
add_executable(3_exp1 sq_stack.h sq_stack.cpp 3_exp1.cpp)
