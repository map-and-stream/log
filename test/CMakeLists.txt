# Test suite for the log library
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(log_test test_log.cpp)
target_link_libraries(log_test PRIVATE isiran::log GTest::gtest_main)
gtest_discover_tests(log_test)
