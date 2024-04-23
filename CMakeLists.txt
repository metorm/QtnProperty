cmake_minimum_required(VERSION 3.18)

# Project
project(QtnProperty
    VERSION 2.0.3
    LANGUAGES CXX
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets LinguistTools)

add_subdirectory(QtnProperty)

# Demo, PEG and Tests are not added to CMake
# Due to the dependency to QSrcipt and Bison/Flex
# handling them requires more work

add_subdirectory(Demo/Simple)