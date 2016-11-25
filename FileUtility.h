//
// Created by Chris Procak on 11/18/2016.
//

#ifndef CHECKERS_FILEUTILITY_H
#define CHECKERS_FILEUTILITY_H


#include "Piece.h"

class FileUtility {
public:
	void WriteToFile(double x, double y, double z, const char * file);
	void ReadFromFileAndPopulateArray(Piece **temp, const char *file);
};


#endif //CHECKERS_FILEUTILITY_H
