//
// Created by Chris Procak on 11/3/2016.
//

#include <GL/gl.h>
#include <GL/glut.h>
#include "Piece.h"

void Piece::DrawPiece(double x, double y, double z) {
	glPushMatrix();
	glTranslated(x, y, z);
	glScaled(0.1, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
}