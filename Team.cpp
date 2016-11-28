//
// Created by Chris Procak on 11/6/2016.
//

#include "Team.h"
#include "CameraViewUtility.h"
#include "Piece.h"
#include "FileUtility.h"

CameraViewUtility cameraViewTeam;
FileUtility fileUtility;

const int sizeOfTeam = 12;
Piece * GreenPieces[sizeOfTeam];
Piece * RedPieces[sizeOfTeam];
Piece * temp[sizeOfTeam];

void DrawRedTeam() {
	cameraViewTeam.Lights(0.831f, 0.141f, 0.149f);
	for(int x = 0; x < sizeOfTeam; x++)
		if(RedPieces[x]->State != 'c')
			RedPieces[x]->DrawPiece(RedPieces[x]->State);
}

void DrawGreenTeam() {
	cameraViewTeam.Lights(0.235f, .553f, 0.051f);
	for(int x = 0; x < sizeOfTeam; x++)
		if(GreenPieces[x]->State != 'c')
			GreenPieces[x]->DrawPiece(GreenPieces[x]->State);
}

void InitializeArrayWithEmptyPieces() {
	for(int i = 0; i < sizeOfTeam; i++) {
		RedPieces[i] = new Piece();
		GreenPieces[i] = new Piece();
		temp[i] = new Piece();
	}

}
void CreateArrayWithPieces() {
	InitializeArrayWithEmptyPieces();
	fileUtility.ReadFromFileAndPopulateArray(GreenPieces, sizeOfTeam, "GreenMove37.dat");
	fileUtility.ReadFromFileAndPopulateArray(RedPieces, sizeOfTeam, "RedMove37.dat");
}
void Team::DrawTeam() {
	CreateArrayWithPieces();
	DrawRedTeam();
	DrawGreenTeam();
}
