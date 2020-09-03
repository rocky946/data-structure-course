cmake_minimum_required(VERSION 3.14)
project(chapter09)

set(CMAKE_CXX_STANDARD 14)

add_executable(seq_search seq_list.h seq_list.cpp seq_search.cpp)
add_executable(bin_search seq_list.h seq_list.cpp bin_search.cpp)
add_executable(block_search seq_list.h seq_list.cpp block_search.cpp)

add_executable(test_bst bst.h bst.cpp test_bst.cpp)
add_executable(9_4 bst.h bst.cpp 9_4.cpp)

add_executable(test_hash_open hash_open.h hash_open.cpp test_hash_open.cpp)
add_executable(test_hash_chain hash_chain.h hash_chain.cpp test_hash_chain.cpp)




