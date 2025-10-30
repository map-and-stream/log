cmake_minimum_required(VERSION 3.10)
project(log)

set(CMAKE_CXX_STANDARD 17)
set(LIB_ALIAS isiran::log)
# set(CMAKE_INSTALL_PREFIX "../output" CACHE PATH "Install path prefix" FORCE)


# Build the example
add_subdirectory(src)
if(LOG_BUILD_TESTS)
    add_subdirectory(test)
else()
    message("-- LOG_BUILD_TESTS is not set")
endif()
if(LOG_BUILD_EXAMPLE)
    add_subdirectory(example)
else()
    message("-- LOG_BUILD_EXAMPLE is not set")
endif()

