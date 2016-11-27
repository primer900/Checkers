//
// Created by Chris Procak on 10/14/2016.
//

#include <GL/glut.h>
#include "CameraViewUtility.h"
#include "Board.h"
#include "Team.h"

CameraViewUtility cameraViewUtility;
Board board;
Team team;

void DrawCheckerBoardAndPieces() {
	cameraViewUtility.SetView();
	cameraViewUtility.SetCamera();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	board.DrawBoard();
	team.DrawTeam();

	glFlush();
}

void Mouse(int button, int state, int x, int y) {
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(DrawCheckerBoardAndPieces);
	glutMouseFunc(Mouse);
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
