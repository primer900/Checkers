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
	double x = -1.5;
	while(x < 0.5){
		checkerPiece.DrawCheckerPiece(x + 0.1, -0.6, 0);
		x += 0.5;
	}

	x = -1;
	while(x < 1) {
		checkerPiece.DrawCheckerPiece(x + 0.1, -0.3, 0);
		x += 0.5;
	}
}

void DrawBlackTeam() {
	cameraViewUtility.Lights(0.0f, 0.0f, 0.0f);
	double x = 1.5;
	while(x > -0.5) {
		checkerPiece.DrawCheckerPiece(x - 0.1, 0.6, 0);
		x -= 0.5;
	}

	x = 1;
	while(x > -1) {
		checkerPiece.DrawCheckerPiece(x - 0.1, 0.3, 0);
		x -= 0.5;
	}
}

void DrawCheckerPieces() {
	cameraViewUtility.SetView();
	cameraViewUtility.SetCamera();

	//Drawing
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
	glutDisplayFunc(DrawCheckerPieces);
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
