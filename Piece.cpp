//
// Created by Chris Procak on 11/3/2016.
//

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdio>
#include "Piece.h"

Piece::Piece() {}

void Piece::DrawPiece(char state) {
	switch (state) { //The switch case will draw either a normal piece or a kinged piece.
		case 'n':
			glPushMatrix();
			glTranslated(x, y + 0.05, z); // + 0.05 is there to correct for translation in the y direction.
			glScaled(0.1, 0.1, 0.1);
			glRotated(90, 1, 0, 0);
			DrawCylinder();
			DrawDisk();
			glPopMatrix();
			break;
		case 'k':
			glPushMatrix();
			glTranslated(x, y, z);
			glScaled(0.1, -0.2, 0.1); // -0.2 is for y so that the checker piece can actually become twice the size.
			glRotated(90, 1, 0, 0);
			DrawCylinder();
			DrawDisk();
			glPopMatrix();
			break;
		default:
			printf("Error drawing the pieces\n");
			break;
	}
}

void Piece::SetPosition(double x_position, double y_position, double z_position) {
	x = x_position;
	y = y_position;
	z = z_position;
}

Piece::~Piece(void) {
	gluDeleteQuadric(quad);
}

void Piece::SetState(char state) {
	State = state;
	quad = gluNewQuadric(); //glutNewQuadric is needed in order to get the cylinder and disks to draw.
	gluQuadricNormals(quad, GLU_SMOOTH);
}

void Piece::DrawCylinder() {
	gluCylinder(quad, 1.0, 1.0, 1.0, 10, 10);
}

void Piece::DrawDisk() {
	gluDisk(quad, 0.0, 1.0, 10, 10);
}
