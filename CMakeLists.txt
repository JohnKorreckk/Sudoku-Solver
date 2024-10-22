cmake_minimum_required(VERSION 3.20)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 20)

# Define a variable containing a list of source files for the project
set(SOURCE_FILES
        main.cpp
        SudokuBoard.cpp
        SudokuBoard.h
)
add_library(SudokuBoard STATIC SudokuBoard.cpp)

# Create the main executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Include the Tests subdirectory
add_subdirectory(Tests)
