//
// Created by Chris Procak on 11/6/2016.
//

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "Team.h"
#include "CameraViewUtility.h"
#include "Piece.h"
#include "FileUtility.h"

CameraViewUtility cameraViewTeam;
FileUtility fileUtility;

const int sizeOfTeam = 12;
Piece * BlackPieces[sizeOfTeam];
Piece * RedPieces[sizeOfTeam];
Piece * temp[sizeOfTeam];

void DrawRedTeam() {
	cameraViewTeam.Lights(1.0f, 0.0f, 0.0f);
	for(int x = 0; x < sizeOfTeam; x++)
		RedPieces[x]->DrawPiece();

/*	for(int x = 0; x < 4; x++) {
		RedPieces[x]->SetPosition(0.5 * x - 1, -0.8, 0);
		RedPieces[x]->DrawPiece();
		fileUtility.WriteToFile(RedPieces[x]->x, RedPieces[x]->y, RedPieces[x]->z, "RedMove0.dat");
	}
	for(int x = 0; x < 4; x++) {
		RedPieces[x + 4]->SetPosition(0.5 * x - 0.75, -0.8, -0.25);
		RedPieces[x + 4]->DrawPiece();
		fileUtility.WriteToFile(RedPieces[x + 4]->x, RedPieces[x + 4]->y, RedPieces[x + 4]->z, "RedMove0.dat");
	}
	for(int x = 0; x < 4; x++) {
		RedPieces[x + 8]->SetPosition(0.5 * x - 1, -0.8, -0.5);
		RedPieces[x + 8]->DrawPiece();
		fileUtility.WriteToFile(RedPieces[x + 8]->x, RedPieces[x + 8]->y, RedPieces[x + 8]->z, "RedMove0.dat");
	}*/
}

void DrawBlackTeam() {
	cameraViewTeam.Lights(0.0f, 0.0f, 0.0f);
	for(int x = 0; x < sizeOfTeam; x++)
		BlackPieces[x]->DrawPiece();

/*	for(int x = 0; x < 4; x++) {
		BlackPieces[x]->SetPosition(0.5 * x - 0.75, -0.8, -1.25);
		BlackPieces[x]->DrawPiece();
		fileUtility.WriteToFile(BlackPieces[x]->x, BlackPieces[x]->y, BlackPieces[x]->z, "BlackMove0.dat");
	}
	for(int x = 0; x < 4; x++) {
		BlackPieces[x + 4]->SetPosition(0.5 * x - 1, -0.8, -1.5);
		BlackPieces[x + 4]->DrawPiece();
		fileUtility.WriteToFile(BlackPieces[x + 4]->x, BlackPieces[x + 4]->y, BlackPieces[x + 4]->z, "BlackMove0.dat");
	}
	for(int x = 0; x < 4; x++) {
		BlackPieces[x + 8]->SetPosition(0.5 * x - 0.75, -0.8, -1.75);
		BlackPieces[x + 8]->DrawPiece();
		fileUtility.WriteToFile(BlackPieces[x + 8]->x, BlackPieces[x + 8]->y, BlackPieces[x + 8]->z, "BlackMove0.dat");
	}*/
}

void InitializeArrayWithEmptyPieces() {
	for(int i = 0; i < sizeOfTeam; i++) {
		RedPieces[i] = new Piece();
		BlackPieces[i] = new Piece();
		temp[i] = new Piece();
	}
}

void CreateArrayWithPieces() {
	InitializeArrayWithEmptyPieces();
	fileUtility.ReadFromFileAndPopulateArray(BlackPieces, sizeOfTeam, "BlackMove0.dat");
	fileUtility.ReadFromFileAndPopulateArray(RedPieces, sizeOfTeam, "RedMove0.dat");
}
void Team::DrawTeam(const char * color) {
	CreateArrayWithPieces();
	if(strcmp(color, "red") == 0)
		DrawRedTeam();
	else if(strcmp(color, "black") == 0)
		DrawBlackTeam();
	else{
		printf("There was an error in the inputting of teams");
		exit(1);
	}
}
