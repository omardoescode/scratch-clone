cmake_minimum_required(VERSION 3.16)

project(utils VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

set(HEADERS 
  include/Event.hpp
  include/Observable.hpp
  include/Observer.hpp
  include/Vector.hpp
)

set(SOURCES 
  src/Observable.cpp
)

add_library(utils ${SOURCES} ${HEADERS})

target_include_directories(utils PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
