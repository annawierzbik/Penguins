#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "penguin.h"
#include "move.h"

//interprets command line parameters
//phase is 0 if placement, 1 if movement
//penguins is number of penguins of the player
//name is 1 when name should be displayed
//input_ID is the id of the element of argv containing the input file
//output_ID is the id of the element of argv containing the output file
//returns 1 if the interpretation was successful
int interpret(int argc, char* argv[], int* phase, int* penguins, int* name, int* input_ID, int* output_ID);

//returns the number of penguins in the penguins= parameter
int penguins_no(char* str);

//returns 1 if str is a name of a txt file
int is_txt(char* str);

//reads state of the game from the input file
//if my_ID is on the list, assigns us the proper player number
int read_file(char* argv[], int input_ID, int board[N][N], struct player players[P], char* my_ID, int* my_number, int * row, int *col);

//writes state of the game to the output file
int write_file(char* argv[], int input_ID, int board[N][N], struct player players[P]);

//a move in the placement phase - one penguin is placed
int placement(int n, int m, int penguins, struct player* my_player, int my_number, int board[N][N]);

//a move in the movement phase - one penguin is moved
int movement(struct player* my_player, int board[N][N]);
