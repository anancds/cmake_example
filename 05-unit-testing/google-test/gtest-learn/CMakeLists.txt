# enable CTest testing
project(foo)
enable_testing()
message(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
# Add a testing executable
add_executable(foo  foo_test.cpp foo.cpp)

target_link_libraries(foo
        GTest::GTest
        GTest::Main
        GMock::GMock
        GMock::Main
        )

add_test(test_all foo)