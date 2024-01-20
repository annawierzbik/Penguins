#include <stdio.h>
#include <string.h>
#include "structures.h"



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


//a move in the movement phase - finding player's penguins that can move, choosing whing floe the penguins should be moved to
/// @param cols number of columns of the board, @param rows number of rows of the board, @param penguins number of penguins per player,
/// @param my_number player's number, @param my_player the player placing the fish (struct), @param board 2-dim array containing all floes,
/// @return 0 (success) / 1 (penguins can't move) /2 (no penguins were found)/ 3 (error)
int movement(int cols, int rows,int penguins, int board[N][N], int my_number, struct player* my_player);

// finds coordinates of player's penguins
/// @param cols number of columns of the board, @param rows number of rows of the board, @param penguins number of penguins per player,
/// @param my_player the player placing the fish (struct), @param my_number player's number, @param board 2-dim array containing all floes,
/// @returns none
void find_my_penguins(int cols, int rows, int penguins, int board[N][N], int my_number, struct player* my_player);

//check if any of player's penguins can move
/// @param cols number of columns of the board, @param rows number of rows of the board, @param penguins number of penguins per player,
/// @param my_number player's number, @param my_player the player placing the fish (struct), @param board 2-dim array containing all floes,
/// @return 0 (no penguin can move) / 1 (at least one penguin can move)
int can_move(int cols, int rows, int penguins, int board[N][N], int my_number, struct player* my_player);

//finds index of the penguing that can move, that penguin will be moved
/// @param cols number of columns of the board, @param rows number of rows of the board, @param penguins number of penguins per player,
/// @param my_number player's number, @param my_player the player placing the fish (struct), @param board 2-dim array containing all floes,
/// @return index of the penguin that will be moved
int choose_penguin(int cols, int rows, int penguins, int board[N][N], int my_number, struct player* my_player);

//counts fish on the right side of the penguin
///@param x first coordinate of the penguin, @param y second coordinate of the penguin
/// @param cols number of columns of the board, @param rows number of rows of the board, @param board 2-dim array containing all floes,
/// @return number of the fish on the right
int fish_right(int x, int y, int board[N][N], int cols, int rows);

//counts fish on the left side of the penguin
///@param x first coordinate of the penguin, @param y second coordinate of the penguin
/// @param cols number of columns of the board, @param rows number of rows of the board, @param board 2-dim array containing all floes,
/// @return number of the fish on the left
int fish_left(int x, int y, int board[N][N], int cols, int rows);

//counts fish above the penguin
///@param x first coordinate of the penguin, @param y second coordinate of the penguin
/// @param cols number of columns of the board, @param rows number of rows of the board, @param board 2-dim array containing all floes,
/// @return number of the fish above the penguin
int fish_up(int x, int y, int board[N][N], int cols, int rows);

//counts fish above the penguin
///@param x first coordinate of the penguin, @param y second coordinate of the penguin
/// @param cols number of columns of the board, @param rows number of rows of the board, @param board 2-dim array containing all floes,
/// @return number of the fish above the penguin
int fish_down(int x, int y, int board[N][N], int cols, int rows);