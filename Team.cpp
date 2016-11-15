//
// Created by Chris Procak on 11/6/2016.
//

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "Team.h"
#include "CameraViewUtility.h"
#include "Piece.h"

CameraViewUtility cameraViewTeam;

Piece * BlackPieces[8];
Piece * RedPieces[8];

void DrawRedTeam() {
	cameraViewTeam.Lights(1.0f, 0.0f, 0.0f);

	for(int x = 0; x < 4; x++) {
		RedPieces[2 * x]->SetPosition(0.5 * x - 0.75, -0.8, 0);
		RedPieces[2 * x]->DrawPiece();
		RedPieces[2 * x + 1]->SetPosition(0.5 * x - 1, -0.8, -0.25);
		RedPieces[2 * x + 1]->DrawPiece();
	}
}

void DrawBlackTeam(bool moveBlackPiece) {
	cameraViewTeam.Lights(0.0f, 0.0f, 0.0f);

	if(!moveBlackPiece)
		for(int x = 0; x < 4; x++) {
			BlackPieces[2 * x]->SetPosition(0.5 * x - 1, -0.8, -1.5);
			BlackPieces[2 * x]->DrawPiece();
			BlackPieces[2 * x + 1]->SetPosition(0.5 * x - 0.75, -0.8, -1.75);
			BlackPieces[2 * x + 1]->DrawPiece();

		}
	else
		for(int x = 0; x < 4; x++) {
			if(x == 0) {
				BlackPieces[2 * x]->SetPosition(0.5 * x - 1, - 0.8, -1.25);
				BlackPieces[2 * x]->DrawPiece();
			}
			else {
				BlackPieces[2 * x]->SetPosition(0.5 * x - 1, -0.8, -1.5);
				BlackPieces[2 * x]->DrawPiece();
			}
			BlackPieces[2 * x + 1]->SetPosition(0.5 * x - 0.75, - 0.8, -1.75);
			BlackPieces[2 * x + 1]->DrawPiece();
		}
}

void InitializePieces() {
	for(int i = 0; i < 8; i++) {
		RedPieces[i] = new Piece();
		BlackPieces[i] = new Piece();
	}
}

void Team::DrawTeam(const char * color, bool moveBlackPiece) {
	InitializePieces();
	if(strcmp(color, "red") == 0)
		DrawRedTeam();
	else if(strcmp(color, "black") == 0)
		DrawBlackTeam(moveBlackPiece);
	else{
		printf("There was an error in the inputting of teams");
		exit(1);
	}
}
