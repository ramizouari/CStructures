cmake_minimum_required(VERSION 3.21)
project(CStructures C)

set(CMAKE_C_STANDARD 17)

add_executable(CStructures main.c list.c list.h binary_search_tree.cpp binary_search_tree.h hash_map.c hash_map.h dynamic_array.c dynamic_array.h queue.c queue.h)
