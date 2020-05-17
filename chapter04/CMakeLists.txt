cmake_minimum_required(VERSION 3.14)
project(chapter04)

set(CMAKE_CXX_STANDARD 14)

# 顺序串
add_executable(test_sq_string sq_string.h sq_string.cpp test_sq_string.cpp)
add_executable(4_1 sq_string.h sq_string.cpp 4_1.cpp)
add_executable(4_2 sq_string.h sq_string.cpp 4_2.cpp)

# 链串
add_executable(test_linked_string linked_string.h linked_string.cpp test_linked_string.cpp)
add_executable(4_3 linked_string.h linked_string.cpp 4_3.cpp)
