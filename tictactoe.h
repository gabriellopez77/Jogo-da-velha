#pragma once

#include <iostream>

const int sizeY = 3;
const int sizeX = 5;
extern char board[sizeY][sizeX];

extern bool turn;  //true: X; false: O;
extern bool gameloop; //main gameloop;
extern int roundCount;

void printBoard();
void drawBase();
void round();
char set();
void checkWinner();
void checkDraw();
