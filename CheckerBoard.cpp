//
// Created by Chris Procak on 10/14/2016.
//

#include <GL/glut.h>


void View() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winHt = 1.0;
	glOrtho(-winHt*72/48.0, winHt*72/48.0, -winHt, winHt, 0.1, 100.0);
}

void Camera() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.5, 1.5, 2, 0, 0, 0, 0.0, 1.0, 0.0);
}

void DrawCheckerPiece() {
	GLfloat mat_ambient[] = { 1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat mat_diffuse[] = {1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat mat_specular[] = {1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat mat_shininess[] = {50.0f};
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	GLfloat lightIntensity[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat light_position[] = {2.0f, 6.0f, 3.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	View();
	Camera();

	//Drawing
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	double x = -1.5;
	while(x < 0.5){
		glPushMatrix();
		glTranslated(x + 0.1, -1, 0);
		glScaled(0.1, 0.1, 0.1);
		glutSolidCube(1.0);
		glPopMatrix();

		x += 0.5;
	}

	x = -1;
	while(x < 1) {
		glPushMatrix();
		glTranslated(x + 0.1, -0.5, 0);
		glScaled(0.1, 0.1, 0.1);
		glutSolidCube(1.0);
		glPopMatrix();

		x += 0.5;
	}

	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(DrawCheckerPiece);
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
