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
Piece piece;

void DrawRedTeam() {
	cameraViewTeam.Lights(1.0f, 0.0f, 0.0f);

	for(int x = 0; x < 4; x++) {
		piece.DrawPiece(0.5 * x - 0.75, -0.8, 0);
		piece.DrawPiece(0.5 * x - 1, -0.8, -0.25);
	}
}

void DrawBlackTeam() {
	cameraViewTeam.Lights(0.0f, 0.0f, 0.0f);

	for(int x = 0; x < 4; x++) {
		piece.DrawPiece(0.5 * x - 1, -0.8, -1.5);
		piece.DrawPiece(0.5 * x - 0.75, -0.8, -1.75);
	}
}

void Team::DrawTeam(const char * color) {
	if(strcmp(color, "red") == 0)
		DrawRedTeam();
	else if(strcmp(color, "black") == 0)
		DrawBlackTeam();
	else{
		printf("There was an error in the inputting of teams");
		exit(1);
	}
}
