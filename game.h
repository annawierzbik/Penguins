#include "structures.h"

//n, m - dimensions of the board
//pla - number of players
//pen - penguins per player
//players - an array of players w info on the fish and the penguins
//board - the board
//places all the penguins of all the players on the board
void place_penguins(int n, int m, int pla, int pen, struct player players[], int board[][N]);

//n, m - dimensions of the board
//pen - penguins per player
//player_id - the id of the current player
//player - a pointer to the current player
//board - the board
//lets the player move one of their penguins to a new floe and destroys the previous one
void move_penguin(int n, int m, int pen, int player_id, struct player* player, int board[][N]);

//n, m - dimensions of the board
//pla - number of players
//pen - penguins per player
//players - an array of players w info on the fish and the penguins
//board - the board
//the main loop - while any of the players can move it enables one of them to make a move
//this is where the player changes
void play_game(int n, int m, int pla, int pen, struct player players[], int board[][N]);

//pla - number of players
//players - a board of players
//evaluates the game - either declares the winner or a tie
void evaluate_game(int pla, struct player players[]);
