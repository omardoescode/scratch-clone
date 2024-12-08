cmake_minimum_required(VERSION 3.16)

project(Business VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

set(HEADERS 
  include/Game.hpp
  include/Character.hpp

  # Instructions
  include/Instructions/Instruction.hpp
  include/Instructions/InstructionWithValues.hpp
  include/Instructions/InstructionWithStack.hpp
  include/Instructions/InstructionStack.hpp
)

set(SOURCES 
  src/Game.cpp
  src/Character.cpp

  # Instructions
  src/Instructions/Instruction.cpp
  src/Instructions/InstructionWithValues.cpp
  src/Instructions/InstructionWithStack.cpp
  src/Instructions/InstructionStack.cpp
)

add_library(business ${SOURCES} ${HEADERS})

target_include_directories(business PUBLIC
    ${CMAKE_SOURCE_DIR}/utils/include
    ${PROJECT_SOURCE_DIR}/include
)
