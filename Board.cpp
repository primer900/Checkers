//
// Created by Chris Procak on 11/6/2016.
//

#include <GL/gl.h>
#include <GL/glut.h>
#include "Board.h"
#include "CameraViewUtility.h"

CameraViewUtility cameraViewBoard;

void DrawCube(double x, double y, double z) {
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(0.25, 0.1, 0.25);
	glutSolidCube(1.0);
	glPopMatrix();
}

void DrawRedSquares() {
	cameraViewBoard.Lights(1.0f, 0.0f, 0.0f);

	for(int x = 0; x < 4; x++)
		for(int z = 0; z < 4; z++) {
			DrawCube(0.5 * x - 1, -0.9, z * -0.5);
			DrawCube(0.5 * x - 0.75, -0.9, 0.5 * z - 1.75);
		}
}

void DrawWhiteSquares() {
	cameraViewBoard.Lights(1.0f, 1.0f, 1.0f);

	for(int x = 0; x < 4; x++)
		for(int z = 0; z < 4; z++) {
			DrawCube(0.5 * x - 1.0, -0.9, -0.5 * z - 0.25);
			DrawCube(0.5 * x  - 0.75, -0.9, -0.5 * z);
		}
}

void Board::DrawBoard() {
	DrawRedSquares();
	DrawWhiteSquares();
}
