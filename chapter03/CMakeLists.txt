cmake_minimum_required(VERSION 3.14)
project(chapter03)

set(CMAKE_CXX_STANDARD 14)

# 顺序栈
add_executable(main main.cpp)
add_executable(test_sq_stack sq_stack.h sq_stack.cpp test_sq_stack.cpp)
add_executable(3_4 sq_stack.h sq_stack.cpp 3_4.cpp)
add_executable(3_exp1 sq_stack.h sq_stack.cpp 3_exp1.cpp)
add_executable(exp_value sq_stack.h sq_stack.cpp sq_stack_double.h sq_stack_double.cpp exp_value.cpp)
add_executable(mg_path sq_stack.h sq_stack.cpp mg_path.cpp)

# 链栈
add_executable(test_linked_stack linked_stack.h linked_stack.cpp test_linked_stack.cpp)
add_executable(3_5 linked_stack.h linked_stack.cpp 3_5.cpp)

# 顺序队
add_executable(test_sq_queue sq_queue.h sq_queue.cpp test_sq_queue.cpp)
# 环形队列
add_executable(test_sq_queue_c sq_queue.h sq_queue_c.cpp test_sq_queue_c.cpp)
add_executable(3_7 sq_queue_c1.h sq_queue_c1.cpp 3_7.cpp)
add_executable(number sq_queue.h sq_queue_c.cpp number.cpp)

# 链队
add_executable(test_linked_queue linked_queue.h linked_queue.cpp test_linked_queue.cpp)
add_executable(3_8 3_8.cpp)