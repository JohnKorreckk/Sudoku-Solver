/**
 * @file SudokuBoardTests.cpp
 * @author John Korreck
 */

#include "../SudokuBoard.h"
#include <gtest/gtest.h>

// Test for valid Sudoku board initialization
TEST(SudokuBoardTest, ValidBoard) {
    std::vector<std::vector<char>> validBoard = {
        {'1', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'}
    };

    EXPECT_NO_THROW(SudokuBoard board(validBoard));
}

// Test for invalid Sudoku board initialization
TEST(SudokuBoardTest, InvalidBoard) {
    std::vector<std::vector<char>> invalidBoard = {
        {'5', '3', '0', '0', '7', '0', '0', '0', '0'},
        {'6', '0', '0', '1', '9', '5', '0', '0', '0'},
        {'0', '9', '8', '0', '0', '0', '0', '6', '5'}, // Invalid because of duplicate '5'
        {'8', '0', '0', '0', '6', '0', '0', '0', '3'},
        {'4', '0', '0', '8', '0', '3', '0', '0', '1'},
        {'7', '0', '0', '0', '2', '0', '0', '0', '6'},
        {'0', '6', '0', '0', '0', '0', '2', '8', '0'},
        {'0', '0', '0', '4', '1', '9', '0', '0', '5'},
        {'0', '0', '0', '0', '8', '0', '0', '7', '9'}
    };

    EXPECT_THROW(SudokuBoard board(invalidBoard), std::invalid_argument);
}

// Test for solving a Sudoku puzzle
TEST(SudokuBoardTest, SolveSudoku) {
    std::vector<std::vector<char>> board =
    {
        {'5', '3', '0', '0', '7', '0', '0', '0', '0'},
        {'6', '0', '0', '1', '9', '5', '0', '0', '0'},
        {'0', '9', '8', '0', '0', '0', '0', '6', '0'},
        {'8', '0', '0', '0', '6', '0', '0', '0', '3'},
        {'4', '0', '0', '8', '0', '3', '0', '0', '1'},
        {'7', '0', '0', '0', '2', '0', '0', '0', '6'},
        {'0', '6', '0', '0', '0', '0', '2', '8', '0'},
        {'0', '0', '0', '4', '1', '9', '0', '0', '5'},
        {'0', '0', '0', '0', '8', '0', '0', '7', '9'}
    };


    std::vector<std::vector<char>> solvedBoard =
    {
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','9'}
    };


    SudokuBoard boardObj(board);
    boardObj.solveSudoku();
    EXPECT_EQ(boardObj.getBoard(), solvedBoard);
}

// Test for displaying the board
TEST(SudokuBoardTest, DisplayBoard) {
    std::vector<std::vector<char>> board = {
        {'5', '3', '0', '0', '7', '0', '0', '0', '0'},
        {'6', '0', '0', '1', '9', '5', '0', '0', '0'},
        {'0', '9', '8', '0', '0', '0', '0', '6', '0'},
        {'8', '0', '0', '0', '6', '0', '0', '0', '3'},
        {'4', '0', '0', '8', '0', '3', '0', '0', '1'},
        {'7', '0', '0', '0', '2', '0', '0', '0', '6'},
        {'0', '6', '0', '0', '0', '0', '2', '8', '0'},
        {'0', '0', '0', '4', '1', '9', '0', '0', '5'},
        {'0', '0', '0', '0', '8', '0', '0', '7', '9'}
    };

    SudokuBoard boardObj(board);
    EXPECT_NO_THROW(boardObj.displayBoard());
}

// Test for empty board initialization
TEST(SudokuBoardTest, EmptyBoard)
{
    std::vector<std::vector<char>> emptyBoard(9, std::vector<char>(9, '0'));
}