cmake_minimum_required(VERSION 3.16)

project(Business VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
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
  include/Commands/InstructionWithExpressions.hpp
  include/Commands/IExpression.hpp
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

  # Commands
  src/Commands/Command.cpp
)

add_library(business ${SOURCES} ${HEADERS})

target_include_directories(business PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/utils/include
)
