cmake_minimum_required(VERSION 3.14)
project(chapter03)

set(CMAKE_CXX_STANDARD 14)

# 顺序栈
add_executable(main main.cpp)
add_executable(test_sq_stack sq_stack.h sq_stack.cpp test_sq_stack.cpp)
add_executable(3_4 sq_stack.h sq_stack.cpp 3_4.cpp)
add_executable(3_exp1 sq_stack.h sq_stack.cpp 3_exp1.cpp)
add_executable(exp_value sq_stack.h sq_stack.cpp sq_stack_double.h sq_stack_double.cpp exp_value.cpp)

# 链栈
add_executable(test_linked_stack linked_stack.h linked_stack.cpp test_linked_stack.cpp)
add_executable(3_5 linked_stack.h linked_stack.cpp 3_5.cpp)