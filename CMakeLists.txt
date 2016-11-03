cmake_minimum_required(VERSION 3.6)
project(Checkers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(CHECKERBOARD CheckerBoard.cpp)
add_executable(CheckerBoard CHECKERBOARD CheckerPiece.cpp CheckerPiece.h CameraViewUtility.cpp CameraViewUtility.h)
target_link_libraries(CheckerBoard glew32 glew32s libopengl32.a libglu32.a libfreeglut.a)
