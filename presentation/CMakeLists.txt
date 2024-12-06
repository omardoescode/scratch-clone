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

set (SOURCES src/GameView.cpp)
set (HEADERS include/GameView.hpp)

add_library(
  presentation
  ${HEADERS}
  ${SOURCES}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

target_link_libraries(presentation PRIVATE sfml-graphics sfml-audio)
target_compile_features(presentation PRIVATE cxx_std_17)

target_include_directories(presentation PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(presentation PRIVATE sfml-graphics sfml-audio)
target_compile_features(presentation PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET presentation
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
            VERBATIM)
endif()

# install(TARGETS p)
