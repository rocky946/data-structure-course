cmake_minimum_required(VERSION 3.14)
project(chapter09)

set(CMAKE_CXX_STANDARD 14)

add_executable(seq_search seq_list.h seq_list.cpp seq_search.cpp)
add_executable(bin_search seq_list.h seq_list.cpp bin_search.cpp)




