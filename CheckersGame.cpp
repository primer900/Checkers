//
// Created by Chris Procak on 10/14/2016.
//

#include <GL/glut.h>
#include "CheckerPiece.h"
#include "CameraViewUtility.h"

CheckerPiece checkerPiece;
CameraViewUtility cameraViewUtility;

void DrawRedTeam() {
	cameraViewUtility.Lights(1.0f, 0.0f, 0.0f);

	for(int x = 0; x < 4; x++) {
		checkerPiece.DrawCheckerPiece(0.5 * x - 0.75, -0.8, 0);
		checkerPiece.DrawCheckerPiece(0.5 * x - 1, -0.8, -0.25);
	}
}

void DrawBlackTeam() {
	cameraViewUtility.Lights(0.0f, 0.0f, 0.0f);

	for(int x = 0; x < 4; x++) {
		checkerPiece.DrawCheckerPiece(0.5 * x - 1, -0.8, -1.5);
		checkerPiece.DrawCheckerPiece(0.5 * x - 0.75, -0.8, -1.75);
	}
}

void DrawCube(double x, double y, double z) {
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(0.25, 0.1, 0.25);
	glutSolidCube(1.0);
	glPopMatrix();
}

void DrawRedSquares() {
	cameraViewUtility.Lights(1.0f, 0.0f, 0.0f);

	for(int x = 0; x < 4; x++)
		for(int z = 0; z < 4; z++) {
			DrawCube(0.5 * x - 1, -0.9, z * -0.5);
			DrawCube(0.5 * x - 0.75, -0.9, 0.5 * z - 1.75);
		}
}

void DrawBlackSquares() {
	cameraViewUtility.Lights(0.0f, 0.0f, 0.0f);

	for(int x = 0; x < 4; x++)
		for(int z = 0; z < 4; z++) {
			DrawCube(x * 0.5 - 1.0, -0.9, z * -0.5 - 0.25);
			DrawCube(0.5 * x  - 0.75, -0.9, z * -0.5);
		}
}

void DrawCheckerBoardAndPieces() {
	cameraViewUtility.SetView();
	cameraViewUtility.SetCamera();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawRedSquares();
	DrawBlackSquares();

	DrawRedTeam();
	DrawBlackTeam();

	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(DrawCheckerBoardAndPieces);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glViewport(0, 0, 720, 480);
	glutMainLoop();
	return 0;
}
