cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(main VERSION 1.0)

add_subdirectory(./business)
add_subdirectory(./presentation)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


