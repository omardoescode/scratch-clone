cmake_minimum_required(VERSION 3.10)

project(Business VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

set(SOURCES 
  src/Game.cpp
  src/Character.cpp
  src/Instructions/Instruction.cpp
  src/Instructions/InstructionWithValues.cpp
  src/Instructions/InstructionWithStack.cpp
  src/Instructions/InstructionStack.cpp
)
set(HEADERS 
  include/Game.hpp
  include/Character.hpp
  include/Instructions/Instruction.hpp
  include/Instructions/InstructionWithValues.hpp
  include/Instructions/InstructionWithStack.hpp
  include/Instructions/InstructionStack.hpp
)

add_library(Business ${SOURCES} ${HEADERS})

target_include_directories(Business PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/include
)
