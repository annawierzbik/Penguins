#include "structures.h"

#ifndef _MOVEF_

//n, m - dimensions of the board
//x, y - coordinates of a floe
//board - the board
//checks if a penguin can stand on floe [x][y]
int is_available(int n, int m, int x, int y, int board[][N]);

//n, m - dimensions of the board
//penguin - coordinates of the penguin
//board - the board
//checks if a specific penguin can move
//notice that if any of the four floes surrounding the penguin are available, it can move
int can_penguin_move(int n, int m, struct coordinates penguin, int board[][N]);

//n, m - dimensions of the board
//pen - penguins per player
//player - a pointer to the current player
//board - the board
//checks whether any of pen penguins of the player can move
int can_player_move(int n, int m, int pen, struct player* player, int board[][N]);

//n, m - dimensions of the board
//pla - number of players
//pen - penguins per player
//players - a board of players
//board - the board
//checks whether any penguin of any player can move
int can_any_move(int n, int m, int pla, int pen, struct player players[], int board[][N]);

//x, y - coordinates of a floe
//pen - penguins per player
//player - a pointer to the current player
//returns the index of a penguin of the player located on the floe [x][y]
//if there is no penguin there returns -1
int which_penguin(int x, int y, int pen, struct player* player);

//pen - penguins per player
//player - a pointer to the current player
//lets the player choose one of his penguins by entering its coordinates
int choose_penguin(int pen, struct player* player);

//x, y - current coordinates
//new_x, new_y - new coordinates
//checks whether the move is along the grid lines
int is_grid_line(int x, int y, int new_x, int new_y);

//x, y - current coordinates
//new_x, new_y - new coordinates
//board - the board
//checks whether there are no empty floes or other penguins on the way
int check_move(int x, int y, int new_x, int new_y, int board[][N]);

//n, m - dimensions of the board
//new_x, new_y - new coordinates
//penguin - the current coordinates
//board - the board
//checks if the penguin can move to [new-x][new_y]
int can_move_there(int n, int m, int new_x, int new_y, struct coordinates penguin, int board[][N]);


#endif // _MOVEF_
