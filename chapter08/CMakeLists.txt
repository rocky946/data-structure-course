cmake_minimum_required(VERSION 3.14)
project(chapter08)

set(CMAKE_CXX_STANDARD 14)

add_executable(test_adj_graph adj_graph.h adj_graph.cpp test_adj_graph.cpp)
add_executable(test_mat_graph mat_graph.h mat_graph.cpp test_mat_graph.cpp)
add_executable(8_2 mat_graph.h mat_graph.cpp adj_graph.h adj_graph.cpp 8_2.cpp)

add_executable(dfs adj_graph.h adj_graph.cpp dfs.cpp)
add_executable(8_3 adj_graph.h adj_graph.cpp 8_3.cpp)
add_executable(bfs adj_graph.h adj_graph.cpp bfs.cpp sq_queue.h sq_queue_c.cpp)
