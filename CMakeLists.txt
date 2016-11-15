cmake_minimum_required(VERSION 3.6)
project(Checkers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(CHECKERBOARD
        CheckersGame.cpp
        Piece.cpp Piece.h
        CameraViewUtility.cpp CameraViewUtility.h
        Board.cpp Board.h
        Team.cpp Team.h)
add_executable(CheckerBoard ${CHECKERBOARD})
target_link_libraries(CheckerBoard glew32 glew32s libopengl32.a libglu32.a libfreeglut.a)
