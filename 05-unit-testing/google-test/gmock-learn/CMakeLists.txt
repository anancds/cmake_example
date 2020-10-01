# enable CTest testing
project(gmock-test)
enable_testing()
message(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
# Add a testing executable
add_executable(gmock-test user-gmock-test.cpp)

target_link_libraries(gmock-test
        GTest::GTest
        GTest::Main
        GMock::GMock
        GMock::Main
        )

add_test(test_all gmock-test)

