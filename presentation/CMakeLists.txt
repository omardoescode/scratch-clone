cmake_minimum_required(VERSION 3.16)
project(Presentation VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
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

  # Widgets
  include/Widgets/SectionsWidget.hpp

  # Utils
  include/Utils/BorderRectangle.hpp
  include/Utils/TextBuilder.hpp
  include/Utils/FontFactory.hpp
  include/Utils/Button.hpp
  include/Utils/ButtonConfig.hpp
  include/Utils/Text.hpp
)
set (SOURCES 
  src/App.cpp
  src/AppWindow.cpp

  # Widgets
  src/Widgets/SectionsWidget.cpp

  # Utils
  src/Utils/BorderRectangle.cpp
  src/Utils/TextBuilder.cpp
  src/Utils/FontFactory.cpp
  src/Utils/Button.cpp
  src/Utils/Text.cpp
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
