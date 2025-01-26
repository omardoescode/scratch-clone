cmake_minimum_required(VERSION 3.16)
project(Presentation VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set (HEADERS 
  include/App.hpp
  include/AppWindow.hpp
  include/Widget.hpp

  # Interfaces
  include/Interfaces/Observable.hpp
  include/Interfaces/Observer.hpp
  include/Interfaces/Hoverable.hpp

  # Views
  include/Views/SectionInstructionSetView.hpp
  include/Views/CommandView.hpp

  # Widgets
  include/Widgets/SectionsWidget.hpp
  include/Widgets/InstructionSetView.hpp

  # Utils
  include/Utils/Container.hpp
  include/Utils/RectangularBorder.hpp
  include/Utils/TextBuilder.hpp
  include/Utils/FontFactory.hpp
  include/Utils/Button.hpp
  include/Utils/Text.hpp
  include/Utils/Padding.hpp
  include/Utils/EdgeInsets.hpp
  include/Utils/Center.hpp
  include/Utils/GridView.hpp
  include/Utils/WidgetList.hpp
  include/Utils/WidgetListBuilder.hpp
  include/Utils/Row.hpp
  include/Utils/WithBackground.hpp
  include/Utils/Input.hpp
  include/Utils/NumericalInput.hpp

  # Timer
  include/Timer/Timer.hpp
)

set (SOURCES 
  src/App.cpp
  src/AppWindow.cpp
  src/Widget.cpp

  # Interfaces 
  src/Interfaces/Hoverable.cpp

  # Views
  src/Views/SectionInstructionSetView.cpp
  src/Views/CommandView.cpp

  # Widgets
  src/Widgets/SectionsWidget.cpp
  src/Widgets/InstructionSetView.cpp

  # Utils
  src/Utils/Container.cpp
  src/Utils/RectangularBorder.cpp
  src/Utils/TextBuilder.cpp
  src/Utils/FontFactory.cpp
  src/Utils/Button.cpp
  src/Utils/Text.cpp
  src/Utils/Padding.cpp
  src/Utils/EdgeInsets.cpp
  src/Utils/Center.cpp
  src/Utils/GridView.cpp
  src/Utils/WidgetList.cpp
  src/Utils/WidgetListBuilder.cpp
  src/Utils/Row.cpp
  src/Utils/WithBackground.cpp
  src/Utils/Input.cpp
  src/Utils/NumericalInput.cpp

  # Timer
  src/Timer/Timer.cpp
)

add_library(
  presentation
  ${HEADERS}
  ${SOURCES}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# TODO: Link business to here to use Game::get_instance()
include_directories(${CMAKE_SOURCE_DIR}/business/include)
include_directories(${CMAKE_SOURCE_DIR}/utils/include)
target_link_libraries(presentation PRIVATE sfml-graphics sfml-audio sfml-system)
target_compile_features(presentation PRIVATE cxx_std_17)

target_include_directories(presentation PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/business/include
)
target_precompile_headers(
presentation PUBLIC ${PROJECT_SOURCE_DIR}/include/Precompiled/header.hpp
)
