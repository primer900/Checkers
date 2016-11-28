//
// Created by Chris Procak on 11/18/2016.
//

#include "FileUtility.h"
#include <iostream>
#include <fstream>
using namespace std;

void FileUtility::WriteToFile(double x, double y, double z, const char * file) {
	ofstream move;
	move.open(file, fstream::app);
	move << x << " " << y << " " << z << endl;
	move.close();
}

void FileUtility::ReadFromFileAndPopulateArray(Piece **team, int sizeOfTeam, const char *file) {
	ifstream move;
	double x, y, z;
	char state;
	move.open(file);

	for(int i = 0; i < sizeOfTeam; i ++) {
		move >> x >> y >> z >> state;
		team[i]->SetPosition(x, y , z);
		team[i]->SetState(state);
	}
	move.close();
}
