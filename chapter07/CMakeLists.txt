cmake_minimum_required(VERSION 3.14)
project(chapter07)

set(CMAKE_CXX_STANDARD 14)

add_executable(7_3 7_3.cpp)

add_executable(7_4 7_4.cpp)

add_executable(test_b_tree b_tree.h b_tree.cpp test_b_tree.cpp)
add_executable(recu_order b_tree.h b_tree.cpp recu_order.cpp)
add_executable(7_11 b_tree.h b_tree.cpp 7_11.cpp)
add_executable(7_12 b_tree.h b_tree.cpp 7_12.cpp)
add_executable(7_13 b_tree.h b_tree.cpp 7_13.cpp)
add_executable(7_14 b_tree.h b_tree.cpp 7_14.cpp)
add_executable(7_15 b_tree.h b_tree.cpp 7_15.cpp)
add_executable(7_16 b_tree.h b_tree.cpp 7_16.cpp)
add_executable(non_recu_order b_tree.h b_tree.cpp sq_stack.h sq_stack.cpp non_recu_order.cpp)
add_executable(7_17 b_tree.h b_tree.cpp sq_stack.h sq_stack.cpp 7_17.cpp)

add_executable(level_order b_tree.h b_tree.cpp level_order.cpp)
add_executable(7_18 b_tree.h b_tree.cpp 7_18.cpp)
add_executable(every_level_disp b_tree.h b_tree.cpp every_level_disp.cpp)

add_executable(create_b_tree b_tree.h b_tree.cpp create_b_tree.cpp)
add_executable(7_19 b_tree.h b_tree.cpp 7_19.cpp)
add_executable(trans2 b_tree.h b_tree.cpp trans2.cpp)

add_executable(thread_b_tree thread_b_tree.cpp)

add_executable(huffman huffman.cpp)

add_executable(ufs union_find_set.cpp)