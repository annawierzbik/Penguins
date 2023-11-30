#include "structures.h"


//n, m - dimensions of the board
//pla - number of players
//pen - penguins per player
//lets the player put in the initial data
void put_in_data(int* n, int* m, int* pla, int* pen);

//n, m - dimensions of the board
//pla - number of players
//pen - penguins per player
//checks for all that can be wrong with data
int data_errors(int n, int m, int pla, int pen);

//n, m - dimensions of the board
//pla - number of players
//pen - penguins per player
//returns to the user info on what is wrong with their initial data
int check_data(int n, int m, int pla, int pen);

