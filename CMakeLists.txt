cmake_minimum_required(VERSION 3.10)
project(log)

set(CMAKE_CXX_STANDARD 17)
set(LIB_ALIAS isiran::log)

# Build the example
add_subdirectory(example)
add_subdirectory(test)