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


/// @param cols columns, @param rows rows, @param penguins how many penguins to place,
/// @param my_player the player placing the fish, @param my_number player's number,
/// @param board 2-dim array containing all floes,

//a move in the placement phase - one penguin is placed (and added 1 fish to player's fish)
/// @return 0 (success) / 1 (all penguins placed) / 3 (error)
int placement(int cols, int rows, int penguins, struct player* my_player, int my_number, int board[N][N]);

/// @return the number of penguins placed by the current player / -1 (error)
int count_my_penguins(int cols, int rows, int board[N][N], int my_number);

//funtion counting the fish on the 4 surrounding files
/// @return number of surrounding fish
int count_fish_around(int x, int y, int cols, int rows, int board[N][N]);

//function choosing the best coordinates (based on the amount of fish around) and placing the penguin
//(does not consider other players)
/// @return 0 (success) / 3 (error)
int place_penguin(int cols, int rows, int board[N][N], int my_number, int penguinsPlaced, struct player* my_player);


/**_________________________________________________MOVEMENT FUNCTIONS_________________________________________________**/


//a move in the movement phase - one penguin is moved
int movement(int cols, int rows,int penguins, int board[N][N], int my_number, struct player* my_player);



/**__________________________________________________FILE MANAGEMENT___________________________________________________**/


/// @param argv command line values, @param input_ID/output_ID id of the file name among them,
/// @param board 2-dim array containing all floes, @param players array containing player info,
/// @param pla number of players, @param rows rows, @param cols columns


//reads state of the game from the input file
/// @return 1 (success) / 0 (error)
int read_file(char* argv[], int input_ID, int board[N][N], struct player players[P], int* pla, int* rows, int* cols);

//finds the number of my player or assigns a new one if necessary
/// @return player number
int identify(char* my_ID, struct player players[P], int* pla);

//writes state of the game to the output file
/// @return 1 (success) / 0 (error)
int write_file(char* argv[], int output_ID, int board[N][N], struct player players[P], int pla, int rows, int cols);
