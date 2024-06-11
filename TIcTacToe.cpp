#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>>& b) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}


bool isGameOver(const vector<vector<char>>& b) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (b[i][0] != '.' && b[i][0] == b[i][1] && b[i][1] == b[i][2]) // Check rows
            return true;
        if (b[0][i] != '.' && b[0][i] == b[1][i] && b[1][i] == b[2][i]) // Check columns
            return true;
    }
    // Check diagonals
    if (b[0][0] != '.' && b[0][0] == b[1][1] && b[1][1] == b[2][2])
        return true;
    if (b[0][2] != '.' && b[0][2] == b[1][1] && b[1][1] == b[2][0])
        return true;

    // Check if the board is full
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (b[i][j] == '.')
                return false;
        }
    }

    return true; 
}

// isValid
bool isValidMove(const vector<vector<char>>& b, int r, int c) {
    return r >= 0 && r < 3 && c >= 0 && c < 3 && b[r][c] == '.';
}

void makeMove(vector<vector<char>>& b, int r, int c, char player) {
    b[r][c] = player;
}

// Making the grid

int main() {
    vector<vector<char>> b(3, vector<char>(3, '.')); 
    char player = 'X'; 

    while (!isGameOver(b)) {
        cout << "Current board:" << endl;
        displayBoard(b);

        int r, c;
        cout << "Player " << player << "'s turn. Enter row and column (0-2): ";
        cin >> r >> c;

        if (isValidMove(b, r, c)) {
            makeMove(b, r, c, player);
            player = (player == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    // Game over
    displayBoard(b);
    if (isGameOver(b)) {
        player = (player == 'X') ? 'O' : 'X'; 
        cout << "Player " << player << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
