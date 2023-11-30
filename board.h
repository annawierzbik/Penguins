#include "structures.h"

#ifndef _BOARDF_
//first two parameter are n and m, that are the dimensions of the game
//int [][N] is introducing the board itself
void initialize_board(int, int, int [][N]);

//first two parameter are n and m, that are the dimensions of the game
//int [][N] is introducing the board itself
void create_board(int, int, int [][N]);

//first two parameter are n and m, that are the dimensions of the game
//int [][N] is introducing the board itself
int ones_on_board(int, int, int [][N]);

//first two parameter are n and m, that are the dimensions of the game
//the third command should be the number of players 
// the fourth parameter should be 
//int [][N] is introducing the board itself
int is_board_good(int, int, int, int, int [][N]);

//first two parameter are n and m, that are the dimensions of the game
//int [][N] is introducing the board itself
void display_board(int, int, int [][N]);

#endif //_BOARDF_
