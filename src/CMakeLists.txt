add_library(log STATIC console_logger.cpp)
target_include_directories(log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
