//
// Created by Chris Procak on 11/3/2016.
//

#ifndef CHECKERS_CHECKERPIECE_H
#define CHECKERS_CHECKERPIECE_H


class Piece {
public:
	Piece();
	void DrawPiece(char state);
	void SetPosition(double x_position, double y_position, double z_position);
	void SetState(char state);
	double x, y, z;
	char State;
	~Piece();
};


#endif //CHECKERS_CHECKERPIECE_H
