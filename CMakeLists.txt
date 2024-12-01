cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(MyProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Static Linking
find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

# Add the executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Specify the include directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
    sfml-graphics 
    sfml-window 
    sfml-system
    sfml-audio
)
