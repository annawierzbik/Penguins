// Main unit tests file
#include "unity.h"
#include "board.h"
#include "auto.h"
// IN THIS FILE I HAVE DEFINED THE TESTS WE ARE CONDUCTING

void setUp() {/*meant to set up the enviroment for all unity tests, but I am not using it here*/}

void tearDown() {/*meant to free memory, delete additional test files etc, but we do not need it here*/}


void test_empty_board() {
    //defining a test for count_my_penguins() when the board has 0 penguins on it
    int board[26][26];
    int cols = 5, rows = 6, players = 3;
    initialize_board(cols, rows, board);
    create_board(cols, rows, players, 1, board);
    display_board(cols, rows, board);
    //since we know that there are no penguins we can test the function
    TEST_ASSERT_EQUAL(count_my_penguins(cols, rows, board, 1), 0);
}


void test_board_with_one() {
    //defining a test for count_my_penguins() when the board has 0 penguins on it
    int board[26][26];
    int cols = 5, rows = 6, players = 3;
    initialize_board(cols, rows, board);
    create_board(cols, rows, players, 1, board);
    display_board(cols, rows, board);
    printf("changing some floe values");
    board[cols-2][rows-1] = 1;
    board[cols-1][rows-1] = 2;
    board[cols-3][rows-2] = 1;
    board[cols-1][rows-4] = 0;
    display_board(cols, rows, board);
    //since we know that there are no penguins we can test the function
    TEST_ASSERT_EQUAL(count_my_penguins(cols, rows, board, 1), 2);
}

void test_invalid_board() {
    //defining a test for count_my_penguins() when the board has 0 penguins on it
    int board[26][26];
    int cols = 5, rows = 6, players = 3;
    initialize_board(cols, rows, board);
    create_board(cols, rows, players, 1, board);
    display_board(cols, rows, board);
    board[cols-2][rows-1] = 70;
    printf("Assigned a value too big for our board");
    display_board(cols, rows, board);
    //since we know that there are no penguins we can test the function
    TEST_ASSERT_EQUAL(count_my_penguins(cols, rows, board, 1), -1);
}

int main(void)  {
    UNITY_BEGIN();
    
    RUN_TEST(test_empty_board);
    RUN_TEST(test_board_with_one);
    RUN_TEST(test_invalid_board);

    UNITY_END();
    
    return 0;   
}
