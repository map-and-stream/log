find_package(Qt6 REQUIRED COMPONENTS Core Test)
set(CMAKE_AUTOMOC ON)
add_library(encrypt STATIC
    qaesencryption.cpp
    qaesencryption.h
    encrypthelper.cpp
    encrypthelper.h
    decrypthelper.cpp
    decrypthelper.h
)
target_link_libraries(encrypt PUBLIC Qt6::Core)
target_include_directories(encrypt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set C++ standard
target_compile_features(encrypt PUBLIC cxx_std_17)

# Optionally build tests for the encrypt module using Qt Test (QTest)
option(ENCRYPT_BUILD_TESTS "Build encrypt tests (uses Qt6 Test module)" ON)
if(ENCRYPT_BUILD_TESTS)
    enable_testing()

    add_executable(encrypt_roundtrip_test
        tests/encrypt_roundtrip.cpp
    )
    target_link_libraries(encrypt_roundtrip_test PRIVATE encrypt Qt6::Core Qt6::Test)
    target_include_directories(encrypt_roundtrip_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    # Ensure moc runs for Q_OBJECT in test
    set_target_properties(encrypt_roundtrip_test PROPERTIES AUTOMOC ON)

    add_test(NAME encrypt_roundtrip COMMAND encrypt_roundtrip_test)
endif()
