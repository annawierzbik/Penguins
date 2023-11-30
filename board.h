#include "structures.h"

#ifndef _BOARDF_
//first two parameter are n and m, that are the dimensions of the game
//int [][N] is introducing the board itself
//this function initialize the board with the parameters received from the players
void initialize_board(int, int, int [][N]);

//first two parameter are n and m, that are the dimensions of the game
//int [][N] is introducing the board itself
//we create the board with random values from 0-3: (0 is for ice flows and 1,2and3 are the number of penguins)
void create_board(int, int, int [][N]);

//first two parameter are n and m, that are the dimensions of the game
//int [][N] is introducing the board itself
//this function counts the number of ones that are in our board that was created randomly
int ones_on_board(int, int, int [][N]);

//first two parameter are n and m, that are the dimensions of the game
//the third command should be the number of players 
// the fourth parameter should be 
//int [][N] is introducing the board itself
//we chech if there are enough ones, the number of ones should be bigger than the vakue we get from multiplying the number of players by the numbers of penguins per player
int is_board_good(int, int, int, int, int [][N]);

//first two parameter are n and m, that are the dimensions of the game
//int [][N] is introducing the board itself
//a function to display the board
void display_board(int, int, int [][N]);

#endif //_BOARDF_



