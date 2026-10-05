cmake_minimum_required(VERSION 3.16)
project(ShellEmulator CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED_ON)

find_package(SFML 3 QUIET COMPONENTSGraphics Window System)
if(NOT SMFL_FOUND)
    message(STATUS "SMFL 3 not found. Fetching...")
    include(FetchContent)
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SMFL/SFML.git
        GIT_TAG 3.0.0
    )
    fETCHcONTENT_mAKEaVAILABLE(sfml)
endif()

add_executable(ShellEmulator
    src/Emulator.hpp
    src/Emulator.cpp
)

target_link_libraries(ShellEmulator PRIVATE SFML::Graphics SFML:Window SFML::System)