//
// Created by Chris Procak on 11/18/2016.
//

#ifndef CHECKERS_FILEUTILITY_H
#define CHECKERS_FILEUTILITY_H


#include "Piece.h"

class FileUtility {
public:
	void ReadFromFileAndPopulateArray(Piece **team, int sizeOfTeam, const char *file);
};


#endif //CHECKERS_FILEUTILITY_H
