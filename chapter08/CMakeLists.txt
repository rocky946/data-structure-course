cmake_minimum_required(VERSION 3.14)
project(chapter08)

set(CMAKE_CXX_STANDARD 14)

add_executable(test_adj_graph adj_graph.h adj_graph.cpp test_adj_graph.cpp)
add_executable(test_mat_graph mat_graph.h mat_graph.cpp test_mat_graph.cpp)
add_executable(8_2 mat_graph.h mat_graph.cpp adj_graph.h adj_graph.cpp 8_2.cpp)

add_executable(dfs adj_graph.h adj_graph.cpp dfs.cpp)
add_executable(8_3 adj_graph.h adj_graph.cpp 8_3.cpp)
add_executable(bfs adj_graph.h adj_graph.cpp bfs.cpp sq_queue.h sq_queue_c.cpp)

add_executable(8_4 adj_graph.h adj_graph.cpp 8_4.cpp)
add_executable(8_5 adj_graph.h adj_graph.cpp 8_5.cpp)
add_executable(8_6 adj_graph.h adj_graph.cpp 8_6.cpp)
add_executable(8_7 adj_graph.h adj_graph.cpp 8_7.cpp)
add_executable(8_8 adj_graph.h adj_graph.cpp 8_8.cpp)

add_executable(8_9 adj_graph.h adj_graph.cpp 8_9.cpp)
add_executable(8_10 adj_graph.h adj_graph.cpp sq_queue.h sq_queue_c.cpp 8_10.cpp)