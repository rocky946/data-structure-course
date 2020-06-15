cmake_minimum_required(VERSION 3.14)
project(chapter07)

set(CMAKE_CXX_STANDARD 14)

add_executable(test_b_tree b_tree.h b_tree.cpp test_b_tree.cpp)
add_executable(recu_order b_tree.h b_tree.cpp recu_order.cpp)
add_executable(7_11 b_tree.h b_tree.cpp 7_11.cpp)
add_executable(7_12 b_tree.h b_tree.cpp 7_12.cpp)