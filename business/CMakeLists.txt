cmake_minimum_required(VERSION 3.16)

project(Business VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

set(HEADERS 
  include/Game.hpp
  include/Character.hpp
  include/CharacterManager.hpp
  include/DataType.hpp
  include/Time.hpp
  include/Value.hpp

  # Events
  include/Events/EventBroker.hpp
  include/Events/Event.hpp
  include/Events/EventType.hpp
  include/Events/KeyboardEvent.hpp
  include/Events/SignalEvent.hpp

  # Commands
  include/Commands/CommandSet.hpp
  include/Commands/Command.hpp
  include/Commands/CommandPart.hpp
  include/Commands/Instruction.hpp
  include/Commands/InstructionWithSubScript.hpp
  include/Commands/Expression.hpp
  include/Commands/BaseExpression.hpp
  include/Commands/Script.hpp
  include/Commands/ScriptExecution.hpp

  # Command Set
  include/Commands/CommandSet/MoveStepsInstruction.hpp
)

set(SOURCES 
  src/Game.cpp
  src/Character.cpp

  # DTOS
  src/DTOs/Sections.cpp

  # Command
  src/Commands/CommandSet.cpp
  src/Commands/Command.cpp
  src/Commands/Expression.cpp
  src/Commands/Constant.cpp
  src/Commands/Instruction.cpp
  src/Commands/InstructionWithSubScript.cpp
  src/Commands/InstructionSet.cpp
  src/Commands/Script.cpp
  src/Commands/ScriptExecution.cpp

  # Command Set
  src/Commands/CommandSet/MoveStepsInstruction.cpp
)

add_library(business ${SOURCES} ${HEADERS})

target_include_directories(business PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/utils/include
)
