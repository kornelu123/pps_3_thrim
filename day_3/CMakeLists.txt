cmake_minimum_required(VERSION 3.24)

project(day_3)

set(CMAKE_CXX_STANDARD_17)

add_compile_options(-Wall -Wextra -g -fstack-protector-all -fsanitize=address )
add_link_options(-fsanitize=address)
 
add_executable(day_3 "day_3.c")

target_link_libraries(day_3 m)
