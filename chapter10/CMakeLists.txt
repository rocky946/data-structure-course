cmake_minimum_required(VERSION 3.14)
project(chapter10)

set(CMAKE_CXX_STANDARD 14)

# 插入排序
add_executable(insert_sort seq_list.h seq_list.cpp insert_sort.cpp)
add_executable(bin_insert_sort seq_list.h seq_list.cpp bin_insert_sort.cpp)
add_executable(shell_sort seq_list.h seq_list.cpp shell_sort.cpp)

# 交换排序
add_executable(bubble_sort seq_list.h seq_list.cpp bubble_sort.cpp)
add_executable(bubble_sort1 seq_list.h seq_list.cpp bubble_sort1.cpp)
add_executable(quick_sort seq_list.h seq_list.cpp quick_sort.cpp)

# 选择排序
add_executable(select_sort seq_list.h seq_list.cpp select_sort.cpp)
add_executable(heap_sort seq_list.h seq_list.cpp heap_sort.cpp)

# 归并排序
add_executable(2_way_merge_sort seq_list.h seq_list.cpp 2_way_merge_sort.cpp)
add_executable(2_way_merge_sort1 seq_list.h seq_list.cpp 2_way_merge_sort1.cpp)

# 基数排序
add_executable(radix_sort radix_sort.cpp)