cmake_minimum_required(VERSION 3.20)
project(Tests)

# Set the list of test files
set(TEST_FILES
        gtest_main.cpp
        SudokuBoardTests.cpp
)

# Get Google Tests
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)

# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include Google Test directories
include_directories(${gtest_SOURCE_DIR}/include)

# Adding the Tests_run target
add_executable(Tests_run ${TEST_FILES})

# Linking Tests_run with Google Test libraries
target_link_libraries(Tests_run PRIVATE SudokuBoard gtest gtest_main)