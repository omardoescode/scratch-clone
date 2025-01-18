cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(main VERSION 1.0)

add_subdirectory(./business)
add_subdirectory(./presentation)
add_subdirectory(./utils)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE utils)
target_link_libraries(main PRIVATE business)
target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system)
target_link_libraries(main PRIVATE presentation)

target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/presentation/include)
