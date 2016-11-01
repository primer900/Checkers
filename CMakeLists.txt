cmake_minimum_required(VERSION 3.6)
project(Checkers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp)
add_executable(Checkers ${SOURCE_FILES})
target_link_libraries(Checkers glew32 glew32s libopengl32.a libglu32.a libfreeglut.a)

set(CHECKERBOARD CheckerBoard.cpp)
add_executable(CheckerBoard CHECKERBOARD)
target_link_libraries(CheckerBoard glew32 glew32s libopengl32.a libglu32.a libfreeglut.a)
