#include "structures.h"

//places all the penguins of all the players on the board
///@param n dimension of the board (amount of rows), @param m dimension of the board (amount of columns),  @param pla number of players, @param pen penguins per player,
///@param players an array of players, @param board an array storing the board
void place_penguins(int n, int m, int pla, int pen, struct player players[], int board[][N]);

//lets the player move one of their penguins to a new floe and destroys the previous one
///@param n dimension of the board (amount of rows), @param m dimension of the board (amount of columns), @param pen penguins per player
///@param player_id the id of the current player, @param player a pointer to the current player, @param board an array storing the board
void move_penguin(int n, int m, int pen, int player_id, struct player* player, int board[][N]);

//the main loop - while any of the players can move it enables one of them to make a move
//this is where the player changes
///@param n dimension of the board (amount of rows), @param m dimension of the board (amount of columns), @param pla number of players, @param pen penguins per player
/// @param players an array of players w info on the fish and the penguins, @param board an array storing the board
void play_game(int n, int m, int pla, int pen, struct player players[], int board[][N]);

//evaluates the game - either declares the winner or a tie and displays the ranking
/// @param pla  the number of players, @param players an array of players
void evaluate_game(int pla, struct player players[]);
