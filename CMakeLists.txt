cmake_minimum_required(VERSION 3.0)

set(Project "Queens_on_desk")

project( ${Project})

add_library(check_queen STATIC check_queen.cpp)
add_executable(${Project} main.cpp)

target_link_libraries(${Project} check_queen)
