//
// Created by Chris Procak on 11/3/2016.
//

#ifndef CHECKERS_CHECKERPIECE_H
#define CHECKERS_CHECKERPIECE_H
#include <GL/gl.h>
#include <GL/glut.h>

class Piece {
public:
	Piece();
	void DrawPiece(char state);
	void SetPosition(double x_position, double y_position, double z_position);
	void SetState(char state);
	double x, y, z;
	char State;
	GLUquadricObj * quad;
	~Piece();

private:
	void DrawCylinder();
	void DrawDisk();
};


#endif //CHECKERS_CHECKERPIECE_H
