/**
 * @file SudokuBoard.cpp
 * @author John Korreck
 */

#include "SudokuBoard.h"

// Constructor to initialize the Sudoku board and validate the initial configuration
SudokuBoard::SudokuBoard(std::vector<std::vector<char>> board) : mBoard(board) {
    std::unordered_set<char> horizontalSet;
    std::unordered_set<char> verticalSet;
    std::unordered_set<char> boxSet[3][3];
    for (int i = 0; i < 9; i++) {
        horizontalSet.clear();
        verticalSet.clear();
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '0') {
                if (horizontalSet.find(board[i][j])!=horizontalSet.end()) {
                    throw std::invalid_argument("Duplicate found in row " + std::to_string(i));
                }
                horizontalSet.insert(board[i][j]);
            }
            if (board[j][i] != '0') {
                if (verticalSet.find(board[j][i])!=verticalSet.end()) {
                    throw std::invalid_argument("Duplicate found in row " + std::to_string(i));
                }
                verticalSet.insert(board[j][i]);
            }
            if (board[i][j] != '0') {
                if (boxSet[i/3][j/3].find(board[i][j]) != boxSet[i/3][j/3].end()) {
                    throw std::invalid_argument("Duplicate found in row " + std::to_string(i));
                }
                boxSet[i/3][j/3].insert(board[i][j]);
            }
        }
    }
}

// Method to solve the Sudoku puzzle using backtracking
bool SudokuBoard::solveSudoku() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (mBoard[row][col] == '0') {  // Assuming '0' represents an empty cell
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValid(row, col, num)) {
                        mBoard[row][col] = num; // Place the number

                        // Recursively attempt to solve the rest of the board
                        if (solveSudoku()) {
                            return true; // Solution found
                        }

                        mBoard[row][col] = '0'; // Backtrack
                    }
                }
                return false; // No valid number found, trigger backtracking
            }
        }
    }
    return true; // Solved
}


bool SudokuBoard::isValid(int row, int col, char c){
    for(int i=0; i<9; i++){
        if(mBoard[i][col] == c)
            return false;
        if(mBoard[row][i] == c)
            return false;
        if(mBoard[3 * (row/3)  +  i/3][3 * (col/3)  +  i%3]   ==   c)
            return false;
    }

    return true;
}

// Display the current state of the Sudoku board
void SudokuBoard::displayBoard() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            std::cout << (col == 0 ? "| " : " | ") << mBoard[row][col];
        }
        std::cout << " |" << std::endl;
    }
}

// Get the current state of the Sudoku board
std::vector<std::vector<char>> SudokuBoard::getBoard() {
    return mBoard;
}