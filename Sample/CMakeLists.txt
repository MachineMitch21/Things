cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-g -Wall -std=c++14")

option(DEBUG_BUILD "Builds a debug executable" OFF)

project(antisocial_test)


file(GLOB SOURCES src/*.cpp src/*.c src/*.h src/*.hpp )


if (DEBUG_BUILD)
    add_definitions(-D_DEBUG)
    set(CMAKE_BUILD_TYPE DEBUG)
else ()
    set(CMAKE_BUILD_TYPE RELEASE)
endif (DEBUG_BUILD)


add_executable(${PROJECT_NAME} ${SOURCES})

find_library(ANTISOCIAL_LIB antisocial)

target_link_libraries(${PROJECT_NAME} ${ANTISOCIAL_LIB} pthread)