#include <stdio.h>
#include "penguin.h"

//Function asking the user for the coordinates where he wants to place his penguin
//function returns them as a struct coordinates (input)
struct coordinates put_in_coordinates(){

    // we dont need struct coordinates *penguin as argument, the function can take no arguments as it is now
    // if we want to, it can directly modify the coordinates using that pointer and then it will not return anything
    
    //I didn't want to change the coordinates immediately through pointers, bc I wanted to check them first and only after that assign new values to penguins

    int x, y;
    printf("Choose where you want to place your penguin. Please enter the coordinates:\n");
    printf("x: ");
    scanf("%d", &x);
    printf("\ny: ");
    scanf("%d", &y);
    struct coordinates input;
    input.y = y;
    input.x = x;
    return input;
}

//function that takes x and y coordinates, as well as the dimensions of the board n, m
//then it check if  x, y are within the board
//returns either 1 or 0 (used in are_coordinates_good())

int is_on_board(int x, int y, int n, int m){

  if (0 <= x && x < n && 0 <= y && y < m)
    return 1;

  else
    return 0;
}

//function that takes struct coordinates (user input returned by put_in_coordinates())
// as well as the n, m dimensions of the board and the board itself
// this function verifies if the coordinates are correct (ex it calls is_on_board()) and if there is exacty one fish on this floe
// returns 1 or 0 (used in the main loop)
int are_coordinates_good(struct coordinates input, int n, int m, int board[][N]){

  int x = input.x;
  int y = input.y;

  if (board[x][y] == 1 && is_on_board(x, y, n, m) == 1)
    return 0;

  else
    return 1;
  /* Separate function are_coordinates_good() for:
   * check if valid
   * coordinates on board
   * value is 1
   * if not go back to: insert coordinates of a penguin*/
}

//function takes the array storing all players(player[])and number of players (pla) 
//then it initializes the count of the fish collected by each player (player[i].fish) to 0
void initialize_fish(struct player players[], int pla){

    for(int i = 0; i < pla; i++){
        players[i].fish = 0;
    }
}

//this function takes the pointer to the struct player, number of his penguin (int i, changing in a loop in main) and the board
//then it uses the value of board on the coordinates of player' ppenguin to change his score (ex floe value is 2 - two points are added to the score)
void collect_fish(struct player* player, int i, int board[][N]){

    int x = player->penguin[i].x;
    int y = player->penguin[i].y;

    (player -> fish) += board[x][y];

    board[x][y] = 0;

}


