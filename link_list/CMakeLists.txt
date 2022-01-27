cmake_minimum_required(VERSION 3.21)
project(link_list C)

set(CMAKE_C_STANDARD 99)

add_executable(link_list linked_list.c circular_linked_list.c)
