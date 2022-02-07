cmake_minimum_required(VERSION 3.21)
project(link_list C)

set(CMAKE_C_STANDARD 99)

add_executable(link_list Src/linked_list.c Src/circular_linked_list.c Src/double_linked_list.c)
