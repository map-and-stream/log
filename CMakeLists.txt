cmake_minimum_required(VERSION 3.10)
project(log)

set(CMAKE_CXX_STANDARD 17)
set(LIB_ALIAS isiran::log)
# set(CMAKE_INSTALL_PREFIX "../output" CACHE PATH "Install path prefix" FORCE)


# Build the example
add_subdirectory(src)
add_subdirectory(example)
add_subdirectory(test)