#include "structures.h"

#ifndef _BOARDF_


//first two parameter are n and m, that are the dimensions of the game
//int [][N] is introducing the board itself
//this function initialize the board with the parameters received from the players
void initialize_board(int n, int m, int board[][N]);

//first two parameter are n and m, that are the dimensions of the game
//pla - number of players
//pen - penguins per player
//int [][N] is introducing the board itself
//first we generate the floes with ones for placing the penguins
//then we fill in the board with random values from 0-3:
//0 is for ice flows
//1,2 and 3 are the number of fish
void create_board(int n, int m, int pla, int pen, int board[][N]);

//first two parameter are n and m, that are the dimensions of the game
//int [][N] is introducing the board itself
//a function to display the board
void display_board(int n, int m, int board[][N]);

#endif // _BOARDF_

