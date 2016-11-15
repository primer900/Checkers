//
// Created by Chris Procak on 11/3/2016.
//

#include <GL/gl.h>
#include <GL/glut.h>
#include "Piece.h"

Piece::Piece() {}

void Piece::DrawPiece() {
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(0.1, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
}

void Piece::SetPosition(double x_position, double y_position, double z_position) {
	x = x_position;
	y = y_position;
	z = z_position;
}

Piece::~Piece(void) {}

