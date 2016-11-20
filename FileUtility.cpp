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
