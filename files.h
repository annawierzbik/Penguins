#include <stdio.h>
#include <string.h>
#include "structures.h"

///________________________________________________COMMAND LINE MANAGEMENT______________________________________________**/


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
