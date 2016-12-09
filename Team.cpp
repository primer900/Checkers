//
// Created by Chris Procak on 11/6/2016.
//

#include <string>
#include "Team.h"
#include "CameraViewUtility.h"
#include "Piece.h"
#include "FileUtility.h"

using namespace std;

CameraViewUtility cameraViewTeam;
FileUtility fileUtility;

const int sizeOfTeam = 12;
Piece * GreenPieces[sizeOfTeam]; //These represent the different pieces in each team.
Piece * RedPieces[sizeOfTeam];

void DrawRedTeam() {
	cameraViewTeam.Lights(0.831f, 0.141f, 0.149f); //RGB color for a Christmas Red.
	for(int x = 0; x < sizeOfTeam; x++)
		if(RedPieces[x]->State != 'c') //If a piece is captured, do not draw it. 'c' for state means captured.
			RedPieces[x]->DrawPiece(RedPieces[x]->State);
}

void DrawGreenTeam() {
	cameraViewTeam.Lights(0.235f, .553f, 0.051f); //RGB color for a Christmas Green.
	for(int x = 0; x < sizeOfTeam; x++)
		if(GreenPieces[x]->State != 'c')
			GreenPieces[x]->DrawPiece(GreenPieces[x]->State);
}

void InitializeArrayWithEmptyPieces() { //Create the initial empty arrays to be populated.
	for(int i = 0; i < sizeOfTeam; i++) {
		RedPieces[i] = new Piece();
		GreenPieces[i] = new Piece();
	}

}
void CreateArrayWithPieces(int moveNumber) {
	InitializeArrayWithEmptyPieces();
	string greenMoveNumber = "GreenMove" + std::to_string(moveNumber) + ".dat"; //Read the necessary .dat files.
	string redMoveNumber = "RedMove" + std::to_string(moveNumber) + ".dat";
	fileUtility.ReadFromFileAndPopulateArray(GreenPieces, sizeOfTeam, greenMoveNumber.c_str());
	fileUtility.ReadFromFileAndPopulateArray(RedPieces, sizeOfTeam, redMoveNumber.c_str());
}

void Team::DrawTeam(int moveNumber) {
	CreateArrayWithPieces(moveNumber);
	DrawRedTeam();
	DrawGreenTeam();
}
