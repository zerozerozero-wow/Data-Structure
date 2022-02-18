cmake_minimum_required(VERSION 3.21)
project(stack_and_queue C)

set(CMAKE_C_STANDARD 99)

add_executable(stack_and_queue main.c Src/sequential_stack.c Inc/sequential_stack.h Src/linked_stack.c Inc/linked_stack.h Src/sequential_queue.c Inc/sequential_queue.h)
