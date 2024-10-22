/**
* @file SudokuBoard.h
 * @author John Korreck
 *
 * Header file for the SudokuBoard class, which represents a Sudoku board
 * and provides methods to solve the puzzle and display the board.
 */

#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <vector>
#include <unordered_set>
#include <iostream>
#include <stdexcept> // Include this for std::invalid_argument

class SudokuBoard {
private:
 std::vector<std::vector<char>> mBoard; // 2D vector to represent the Sudoku board

 // Check if placing a value is valid in the given row and column
 bool isValid(int row, int col, char val);

public:
 SudokuBoard() = delete; // Disable the default constructor
 // Constructor that takes a reference to a 2D vector of chars
 SudokuBoard(std::vector<std::vector<char>> board);


 // Method to solve the Sudoku puzzle
 bool solveSudoku();

 // Method to display the current state of the board
 void displayBoard();

 // Method to get the current state of the board
 std::vector<std::vector<char>> getBoard();
};

#endif // SUDOKUBOARD_H
