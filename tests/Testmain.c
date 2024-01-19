#include <stdlib.h>
#include "unity.h"
#include "board.h"
#include "auto.h"
#include "files.h"
// IN THIS FILE I HAVE DEFINED THE TESTS WE ARE CONDUCTING

void setUp() {/*meant to set up the enviroment for all unity tests, but I am not using it here*/}

void tearDown() {/*meant to free memory, delete additional test files etc, but we do not need it here*/}


void test_empty_board() {
    //defining a test for count_my_penguins() when the board has 0 penguins on it
    int board[26][26];
    int cols = 5, rows = 6, players = 3;
    initialize_board(cols, rows, board);
    create_board(cols, rows, players, 1, board);
    //display_board(cols, rows, board);
    TEST_ASSERT_EQUAL( 0, count_my_penguins(cols, rows, board, 1));
}

void test_one_penguin() {
    //defining a test for count_my_penguins() when the board has 2 penguins on it
    int board[26][26];
    int cols = 5, rows = 6, players = 3;
    initialize_board(cols, rows, board);
    create_board(cols, rows, players, 1, board);
    board[1][1] = 1;
    board[2][3] = 1;
    //display_board(cols, rows, board);
    TEST_ASSERT_EQUAL( 2, count_my_penguins(cols, rows, board, 1));
}

void test_identify() {
    //defining a test checking if the fucntion finds the player it is supposed to
    char my_ID[10] = "Hania";
    int number_of_players = 3;
    struct player players[number_of_players]; 
    strcpy(players[1].name, "Anna");
    strcpy(players[2].name, "Javier");
    strcpy(players[3].name, "Hania");
    TEST_ASSERT_EQUAL(3, identify(my_ID, players, &number_of_players));
}

int main(void)  {
    UNITY_BEGIN();
    
    RUN_TEST(test_empty_board);
    RUN_TEST(test_one_penguin);
    RUN_TEST(test_identify);

    UNITY_END();
    
    return 0;   
}
