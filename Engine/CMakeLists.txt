cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-g -Wall -std=c++14")

option(DEBUG_BUILD "Builds a debug executable" OFF)

project(antisocial)


file(GLOB SOURCES src/*.cpp src/*.c src/*.h src/*.hpp src/vendor/stb_image/*.cpp src/vendor/imgui/*.cpp src/vendor/ECS/*.cpp)

file(GLOB INCLUDES src/*.h src/*.hpp)

file(GLOB ECS_INCLUDES src/vendor/ECS/*.h)

if (DEBUG_BUILD)
add_definitions(-D_DEBUG)
endif (DEBUG_BUILD)


add_library( ${PROJECT_NAME} SHARED ${SOURCES} )

target_include_directories(${PROJECT_NAME} PUBLIC src/vendor/)

target_link_libraries(${PROJECT_NAME} GLEW glfw3 GL assimp X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt pthread dl)

install(TARGETS antisocial DESTINATION lib)
install(FILES ${INCLUDES} DESTINATION include/Antisocial)
install(FILES ${ECS_INCLUDES} DESTINATION include/Antisocial/vendor/ECS)




