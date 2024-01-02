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

//a move in the placement phase - one penguin is placed (and added 1 fish to player's fish)
/// @param n columns, @param m rows, @param penguins how many penguins per player,
/// @param my_player the player placing the fish, @param my_number player's number, @param board 2-dim array containing all floes,
/// @return 0 (success) / 1 (all penguins placed) / 3 (error)
int placement(int n, int m, int penguins, struct player* my_player, int my_number, int board[N][N]);

//Function returning the amount of penguins the already player has on board (in order to check if player has anymore penguins to place)
int count_my_penguins(int n, int m, int board[N][N], int my_number);

//funtion counting the fish on the 4 surrounding files (in order to choose where to place penguins)
int countFishAround(int x, int y, int n, int m, int board[N][N]);

//function choosing the best coordinates (based on the amount of fish around) and placing the penguin (doesn't consider other players nearby)
///@return 0 (success)/ 3 (error)
int place_penguin(int n, int m, int board[N][N], int my_number, int penguinsPlaced, struct player* my_player);

//a move in the movement phase - one penguin is moved
int movement(struct player* my_player, int board[N][N]);
