#include <iostream>
#include <string>
#include <vector>

using namespace std;


void display(const vector<vector<int>>& board);
bool gameWon(const vector<vector<int>>& board, const int& player);
bool validMove(const vector<vector<int>>& board, const int& x, const int& y);

int main(void) {
	// initialize board
	// 0 = empty, 1 = x, -1 = y
	vector<vector<int>> board(4, vector<int>(4, 0));
	bool playing = true;
	int player = 1;
	int xCoord, yCoord;
	while (playing) {
		system("cls");
		display(board);
		cout << "\nPlayer " << player << "'s turn.\nY coordinate: ";
		cin >> yCoord;
		cout << "\nX coordinate: ";
		cin >> xCoord;
		
		if (!validMove(board, xCoord, yCoord)) {
			cout << "Not a valid move. Enter something to try again\n";
			cin >> xCoord;
		}
		else {
			board[xCoord][yCoord] = player;
			playing = !gameWon(board, player);
			player *= -1;
		}
	}
	player *= -1;

	cout << "Player " << player << " won!";

	return 0;
}

void display(const vector<vector<int>>& board) {
	for (int i = 1; i < 4; ++i) {
		for (int j = 1; j < 4; ++j) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

bool gameWon(const vector<vector<int>>& board, const int& player) {
	int win = player * 3;
	// rows and columns
	int diagonal1 = 0, diagonal2 = 0;

	for (int i = 1; i < 4; ++i) {
		int row = 0;
		int col = 0;
		for (int j = 1; j < 4; ++j) {
			row += board[i][j];
			col += board[j][i];
		}
		if (row == win || col == win) {
			return true;
		}
		diagonal1 += board[i][4 - i];
		diagonal2 += board[4 - i][i];
	}
	if (diagonal1 == win || diagonal2 == win) {
		return true;
	}
	else {
		return false;
	}
}

bool validMove(const vector<vector<int>>& board, const int& x, const int& y) {
	if (x > 3 || y > 3 || x < 1 || y < 1) {
		return false;
	}
	else {
		return board[x][y] == 0;
	}
}
