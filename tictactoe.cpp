#include "tictactoe.h"

char board[sizeY][sizeX] = {};

bool turn = true;
bool gameloop = true;
int roundCount = 0;

void drawBase() {
	board[0][0] = '1';
	board[0][2] = '2';
	board[0][4] = '3';
	board[1][0] = '4';
	board[1][2] = '5';
	board[1][4] = '6';
	board[2][0] = '7';
	board[2][2] = '8';
	board[2][4] = '9';

	board[0][1] = '|';
	board[0][3] = '|';
	board[1][1] = '|';
	board[1][3] = '|';
	board[2][1] = '|';
	board[2][3] = '|';
}

void printBoard() {

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 5; x++)
			std::cout << board[y][x];

		std::cout << std::endl;
	}
}

char set() {
	if (turn)
		return 'X';

	return 'O';
}

void round() {
	bool loop = true;

	int input;
	while(loop) {
		if (turn) { std::cout << "X turn: "; }
		else { std::cout << "O turn: "; }

		std::cin >> input;

		if (input > 0 && input <= 9 ) {
			switch (input) {
			case 1:
				if (board[0][0] != 'X' && board[0][0] != 'O') {
					board[0][0] = set();
					roundCount++;
					loop = false;
				}
			break;
			case 2:
				if (board[0][2] != 'X' && board[0][2] != 'O') {
					board[0][2] = set();
					roundCount++;
					loop = false;
				}
			break;
			case 3:
				if (board[0][4] != 'X' && board[0][4] != 'O') {
					board[0][4] = set();
					roundCount++;
					loop = false;
				}
			break;
			case 4:
				if (board[1][0] != 'X' && board[1][0] != 'O') {
					board[1][0] = set();
					roundCount++;
					loop = false;
				}
			break;
			case 5:
				if (board[1][2] != 'X' && board[1][2] != 'O') {
					board[1][2] = set();
					roundCount++;
					loop = false;
				}
			break;
			case 6:
				if (board[1][4] != 'X' && board[1][4] != 'O') {
					board[1][4] = set();
					roundCount++;
					loop = false;
				}
			break;
			case 7:
				if (board[2][0] != 'X' && board[2][0] != 'O') {
					board[2][0] = set();
					roundCount++;
					loop = false;
				}
			break;
			case 8:
				if (board[2][2] != 'X' && board[2][2] != 'O') {
					board[2][2] = set();
					roundCount++;
					loop = false;
				}
			break;
			case 9:
				if (board[2][4] != 'X' && board[2][4] != 'O') {
					board[2][4] = set();
					roundCount++;
					loop = false;
				}
			break;
			
			default:
				break;
			}
		}

		if (gameloop == false) {
			loop = false;
			std::cout << roundCount << '\n';
		}
	}
	turn = !turn;
}

void checkWinner() {
	for (int vertical = 0; vertical < 3; vertical++) {
		if (board[vertical][0] == board[vertical][2] && board[vertical][2] == board[vertical][4]) {
			std::cout << board[vertical][0] << " Winner the game!\n";
			gameloop = false;
			return;
		}
	}
	for (int horizontal = 0; horizontal < 5; horizontal++) {
		if (board[0][horizontal] != '|')
			if (board[0][horizontal] == board[1][horizontal] && board[1][horizontal] == board[2][horizontal]) {
				std::cout << board[0][horizontal] << " Winner the game!\n";
				gameloop = false;
				return;
			}
	}
	if (board[0][0] == board[1][2] && board[1][2] == board[2][4]) {
		std::cout << board[0][0] << " Winner the game!\n";
		gameloop = false;
		return;
	}

	if (board[0][4] == board[1][2] && board[1][2] == board[2][0]) {
		std::cout << board[0][4] << " Winner the game!\n";
		gameloop = false;
		return;
	}
}

void checkDraw() {
	if (roundCount >= 9 && gameloop) {
		gameloop = false;
		std::cout << "Game ended in a draw!\n";
	}
}