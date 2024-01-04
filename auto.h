#include <stdio.h>
#include <string.h>
#include "structures.h"


/**________________________________________________COMMAND LINE MANAGEMENT______________________________________________**/


/// @param argc argv command line params,
/// @param phase (0 placement / 1 movement), @param penguins penguins to place,
/// @param name whether name is called,
/// @param input_ID id of the input file name, @param output_ID id of the output file name,
/// @param str a string to consider,

//interprets command line parameters
/// @return 1 (success) / 0 (error)
int interpret(int argc, char* argv[], int* phase, int* penguins, int* name, int* input_ID, int* output_ID);

/// @return the number of penguins in the penguins= parameter
int penguins_no(char* str);

/// @return 1 (str is a file name) / 0 (it is not)
int is_txt(char* str);


/**_________________________________________________PLACEMENT FUNCTIONS________________________________________________**/

//a move in the placement phase - one penguin is placed (and added 1 fish to player's fish)
/// @param cols number of columns of the board, @param rows number of rows of the board, @param penguins number of penguins per player,
/// @param my_player the player placing the fish (struct), @param my_number player's number,
/// @param board 2-dim array containing all floes,
/// @return 0 (success) / 1 (all penguins placed) / 3 (error)
int placement(int cols, int rows, int penguins, struct player* my_player, int my_number, int board[N][N]);

/// @param cols number of columns of the board, @param rows number of rows of the board, @param board 2-dim array containing all floes, @param my_number player's number,
/// @return x the number of penguins placed by the current player / -1 (error)
int count_my_penguins(int cols, int rows, int board[N][N], int my_number);

//funtion counting the fish on the 4 surrounding files
///@param x coordinate on the board (x-th column), @param y coordinate on the board (y-th row), @param cols number of columns of the board, @param rows number of rows of the board, @param board 2-dim array containing all floes,
/// @return the number of surrounding fish
int count_fish_around(int x, int y, int cols, int rows, int board[N][N]);

//function choosing the best coordinates (based on the amount of fish around) and placing the penguin
//(does not consider other players)
/// @param cols number of columns of the board, @param rows number of rows of the board, @param penguins number of penguins per player,
/// @param my_player the player placing the fish (struct), @param my_number player's number, @param board 2-dim array containing all floes,
/// @return 0 (success) / 3 (error)
int place_penguin(int cols, int rows, int board[N][N], int my_number, int penguinsPlaced, struct player* my_player);


/**_________________________________________________MOVEMENT FUNCTIONS_________________________________________________**/


//a move in the movement phase - one penguin is moved
/// @param cols number of columns of the board, @param rows number of rows of the board, @param penguins number of penguins per player,
/// @param my_number player's number, @param my_player the player placing the fish (struct), @param board 2-dim array containing all floes,
/// @return ?
int movement(int cols, int rows,int penguins, int board[N][N], int my_number, struct player* my_player);



/**__________________________________________________FILE MANAGEMENT___________________________________________________**/

//reads state of the game from the input file
/// @param argv command line values, @param input_ID/output_ID id of the file name among them,
/// @param board 2-dim array containing all floes, @param players array containing player info,
/// @param pla number of players, @param rows rows, @param cols columns
/// @return 1 (success) / 0 (error)
int read_file(char* argv[], int input_ID, int board[N][N], struct player players[P], int* pla, int* rows, int* cols);

//finds the number of my player or assigns a new one if necessary
/// @return player number
int identify(char* my_ID, struct player players[P], int* pla);

//writes state of the game to the output file
/// @return 1 (success) / 0 (error)
int write_file(char* argv[], int output_ID, int board[N][N], struct player players[P], int pla, int rows, int cols);
