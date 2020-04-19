cmake_minimum_required(VERSION 3.14)
project(chapter02)

set(CMAKE_CXX_STANDARD 14)

# 顺序表
add_executable(array_list main.cpp array_list.h array_list.cpp)
add_executable(2_3 algorithm2_3.cpp array_list.h array_list.cpp common.h common.cpp)
add_executable(2_4 algorithm2_4.cpp array_list.h array_list.cpp common.h common.cpp)
add_executable(2_5 algorithm2_5.cpp array_list.h array_list.cpp common.h common.cpp)

# 单链表
add_executable(test_linked_list.cpp linked_list.h linked_list.cpp test_linked_list.cpp)
add_executable(2_6 linked_list.h linked_list.cpp algorithm2_6.cpp)
add_executable(2_7 linked_list.h linked_list.cpp algorithm2_7.cpp)
add_executable(2_8 linked_list.h linked_list.cpp algorithm2_8.cpp)

# 双链表
add_executable(test_dlinked_list dlinked_list.h dlinked_list.cpp test_dlinked_list.cpp)
add_executable(2_9 dlinked_list.h dlinked_list.cpp algorithm2_9.cpp)
add_executable(2_10 dlinked_list.h dlinked_list.cpp algorithm2_10.cpp)

# 循环单链表
add_executable(test_clinked_list clinked_list.h clinked_list.cpp test_clinked_list.cpp)
add_executable(2_11 clinked_list.h clinked_list.cpp algorithm2_11.cpp)

# 循环双链表
add_executable(test_cdlinked_list cdlinked_list.h cdlinked_list.cpp test_cdlinked_list.cpp)
add_executable(2_12 cdlinked_list.h cdlinked_list.cpp algorithm2_12.cpp)
add_executable(2_13 cdlinked_list.h cdlinked_list.cpp algorithm2_13.cpp)

# 线性表的应用：表连接
add_executable(test_table_link table_link.h table_link.cpp test_table_link.cpp)

# 有序表顺序存储
add_executable(test_ordered_array_list array_list.h array_list.cpp ordered_array_list.h
        ordered_array_list.cpp test_ordered_array_list.cpp)
add_executable(2_14_1 array_list.h array_list.cpp ordered_array_list.h
        ordered_array_list.cpp algorithm2_14_1.cpp)

# 有序表单链表存储
add_executable(test_ordered_linked_list linked_list.h linked_list.cpp
        ordered_linked_list.h ordered_linked_list.cpp test_ordered_linked_list.cpp)
add_executable(2_14_2 linked_list.h linked_list.cpp
        ordered_linked_list.h ordered_linked_list.cpp algorithm2_14_2.cpp)

# 有序表的应用
add_executable(2_15 linked_list.h linked_list.cpp
        ordered_linked_list.h ordered_linked_list.cpp algorithm2_15.cpp)
add_executable(2_16 linked_list.h linked_list.cpp
        ordered_linked_list.h ordered_linked_list.cpp algorithm2_16.cpp)
add_executable(2_17 array_list.h array_list.cpp ordered_array_list.h
        ordered_array_list.cpp algorithm2_17.cpp)

