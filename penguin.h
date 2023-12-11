#include "structures.h"

#ifndef _PENGF_

//function takes a line from the console
void getstring(char str[]);

//function converts a fragment of string str[] to a single coordinate
//l and r determine the range of ascii codes considered for the coordinate
//i points to the current index of str[]
int fragment(char str[], char l, char r, int* i);

//Function converts the coordinates given as a string (str[]) to numeric x and y
int convert(char str[], int* x, int* y);

//Function asking the user for the coordinates where he wants to place his penguin
//type determines the message printed in the console
//function returns them as a struct coordinates (input)
struct coordinates insert_coordinates(int type);

//function that takes x and y coordinates, as well as the dimensions of the board n, m
//then it checks if  x, y are within the board
//returns either 1 or 0 (used in are_coordinates_good())
int is_on_board(int x, int y, int n, int m);

//function that takes struct coordinates (user input returned by put_in_coordinates())
// as well as the n, m dimensions of the board and the board itself
// this function verifies if the coordinates are correct (ex it calls is_on_board()) and if there is exacty one fish on this floe
int are_coordinates_good(struct coordinates input, int n, int m, int board[][N]);

//function takes the array storing all players(player[])and number of players (pla)
//then it initializes the count of the fish collected by each player (player[i].fish) to 0
void initialize_fish(struct player players[], int pla);

//this function takes the pointer to the struct player, number of his penguin (int i, changing in a loop in main) and the board
//then it uses the value of board on the coordinates of player' ppenguin to change his score (ex floe value is 2 - two points are added to the score)
void collect_fish(int player_id, struct player* player, int i, int board[][N]);

#endif // _PENGF_
