//
// Created by Chris Procak on 11/3/2016.
//

#ifndef CHECKERS_CHECKERPIECE_H
#define CHECKERS_CHECKERPIECE_H


class Piece {
public:
	Piece();
	void DrawPiece();
	void SetPosition(double x_position, double y_position, double z_position);
	double x, y, z;
	~Piece();
};


#endif //CHECKERS_CHECKERPIECE_H
