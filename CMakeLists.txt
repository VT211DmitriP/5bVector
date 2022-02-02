cmake_minimum_required(VERSION 3.20)
project(5b_vector C)

set(CMAKE_C_STANDARD 11)

add_executable(5b_vector main.c libs/algorithms/array/array.c libs/algorithms/array/array.h libs/algorithms/algorithm.c libs/algorithms/algorithm.h libs/data_strustures/vector/vector.c libs/data_strustures/vector/vector.h)

add_subdirectory(libs)
target_link_libraries(5b_vector data_strustures)
target_link_libraries(5b_vector algorithms)