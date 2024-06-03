#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 5;
const char WATER = '~';
const char SHIP = 'S';
const char HIT = 'X';
const char MISS = 'O';

void initializeBoard(vector<vector<char>>& board) {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		vector<char> row(BOARD_SIZE, WATER);
		board.push_back(row);
	}
}

void placeShip(vector<vector<char>>& board) {
	srand(time(0));
	int shipRow = rand() % BOARD_SIZE;
	int shipCol = rand() % BOARD_SIZE;
	board[shipRow][shipCol] = SHIP;
}

void printBoard(const vector<vector<char>>& board) {
	for (const auto& row : board) {
		for (const auto& cell : row) {
			cout << cell << ' ';
		}
		cout << endl;
	}
}

bool isGameOver(const vector<vector<char>>& board) {
	for (const auto& row : board) {
		for (const auto& cell : row) {
			if (cell == SHIP) {
				return false;
			}
		}
	}
	return true;
}

void makeMove(vector<vector<char>>& board, int row, int col) {
	if (board[row][col] == SHIP) {
		cout << "Le has dado" << endl;
		board[row][col] = HIT;
	}
	else {
		cout << "No le has dado" << endl;
		board[row][col] = MISS;
	}
}

int main() {
	vector<vector<char>> board;
	initializeBoard(board);
	placeShip(board);

	cout << "Bienvenido a hundir la flota" << endl;

	while (!isGameOver(board)) {
		printBoard(board);

		int row, col;
		cout << "Introduce tu movimiento (row y column): ";
		cin >> row >> col;
		
		if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
			cout << "Movimiento inválido. Vuelvelo a intentar." << endl;
			continue;
		}

		makeMove(board, row, col);
	}

	cout << "Felicidades! Has hundido el barco!" << endl;
	printBoard(board);

	return 0;
}