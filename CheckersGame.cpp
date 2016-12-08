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
int moveNumber = 0;
bool Animate = false;

enum Options {
	START,
	RESUME,
	STOP,
	RESTART
};

void DrawCheckerBoardAndPieces() {
	cameraViewUtility.SetView();
	cameraViewUtility.SetCamera();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	board.DrawBoard();
	team.DrawTeam(moveNumber);
/*	if(moveNumber < 37)
		moveNumber++;*/

	glFlush();
}

void AnimateCheckerGame(int zero) {
	cameraViewUtility.SetView();
	cameraViewUtility.SetCamera();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	board.DrawBoard();
	team.DrawTeam(moveNumber);

	glutPostRedisplay();
	glutTimerFunc(1000, AnimateCheckerGame, moveNumber);
	if(moveNumber < 37 && Animate)
		moveNumber++;
	glFlush();
}

void menu(int item) {
	switch (item) {
		case START:
			glutTimerFunc(1000, AnimateCheckerGame, 0);
			Animate = true;
			break;
		case RESUME:
			Animate = true;
			break;
		case STOP:
			Animate = false;
			break;
		case RESTART:
			moveNumber = 0;
			break;
		default:
			break;
	}

	glutPostRedisplay();
	return;
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(DrawCheckerBoardAndPieces);

	glutCreateMenu(menu);
	glutAddMenuEntry("Start", START);
	glutAddMenuEntry("Resume", RESUME);
	glutAddMenuEntry("Stop", STOP);
	glutAddMenuEntry("Restart", RESTART);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

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
