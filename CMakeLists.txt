add_executable(step_1_7_15 main.cpp)
add_library(check_queen STATIC check_queen.cpp)
target_link_libraries(step_1_7_15 check_queen)
