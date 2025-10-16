cmake_minimum_required(VERSION 3.10)
project(log_example)

# Bring in the log library target
add_subdirectory(../src ${CMAKE_BINARY_DIR}/isiran_log_src)

add_executable(example main.cpp)
target_link_libraries(example PRIVATE isiran::log)
