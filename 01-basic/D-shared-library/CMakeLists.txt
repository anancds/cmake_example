cmake_minimum_required(VERSION 3.5)

project(hello_shared_library)

############################################################
# Create a library
############################################################

#Generate the shared library from the library sources
add_library(hello_shared_library SHARED
    src/Hello.cpp
)
add_library(hello::library ALIAS hello_shared_library)

target_include_directories(hello_shared_library
    PUBLIC 
        include
)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(hello_shared_library_bin
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( hello_shared_library_bin
    PRIVATE 
        hello::library
)
