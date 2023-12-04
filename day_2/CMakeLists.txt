cmake_minimum_required(VERSION 3.24)

project(day_2)

set(CMAKE_CXX_STANDARD_17)

add_compile_options(-Wall -Wextra -g -fstack-protector-all -fsanitize=address )
add_link_options(-fsanitize=address)
 
add_executable(day_2 "day_2.c")

target_link_libraries(day_2 m)
