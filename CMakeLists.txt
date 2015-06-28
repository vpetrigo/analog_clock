cmake_minimum_required (VERSION 3.1)

set(CMAKE_CXX_COMPILER clang++-3.7)

project(Analog_Clock)

include_directories("../../GUI")
link_directories("../../GUI/lib")

set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")

find_package(FLTK REQUIRED)
include_directories("${FLTK_INCLUDE_DIR}")

add_library(Analog_Dial Analog_dial.cpp)
add_library(Angles Angles.cpp)
target_link_libraries(Analog_Dial Angles)

add_executable(Analog_Clock main.cpp)

set_property(TARGET Analog_Clock PROPERTY CXX_STANDARD 11)
set_property(TARGET Analog_Dial PROPERTY CXX_STANDARD 11)
set_property(TARGET Angles PROPERTY CXX_STANDARD 11)

target_link_libraries(Analog_Clock StGUI)
target_link_libraries(Analog_Clock ${FLTK_LIBRARIES})
target_link_libraries(Analog_Clock Analog_Dial)
