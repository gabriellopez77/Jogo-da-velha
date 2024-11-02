#include "tictactoe.h"

int main() {
	drawBase();

	while (gameloop) {
		printBoard();
		round();
		system("cls");
		checkWinner();
		checkDraw();
	}
	system("pause");
}	