//
// Created by Chris Procak on 11/3/2016.
//

#include <GL/gl.h>
#include <GL/glu.h>
#include "CameraViewUtility.h"

void CameraViewUtility::SetView() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winHt = 1.0;
	glOrtho(-winHt*72/48.0, winHt*72/48.0, -winHt, winHt, 0.1, 100.0);
}

void CameraViewUtility::SetCamera() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.5, 1.5, 2, 0, 0, 0, 0.0, 1.0, 0.0);
}

void CameraViewUtility::Lights(float red, float green, float blue) { //Will set the lights based on RGB colors.
	GLfloat mat_ambient[] = { 1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat mat_diffuse[] = {red, green, blue, 1.0f};
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
}
