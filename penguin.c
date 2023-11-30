#include <stdio.h>
#include "penguin.h"

struct coordinates insert_coordinates(int type){

    int x, y;

    if(type == 0) printf("Insert the coordinates of the floe you want to place your penguin on:\nx: ");
    if(type == 1) printf("Insert the coordinates of the penguin you want to move:\nx: ");
    if(type == 2) printf("Insert the coordinates of the floe you want to move your penguin to:\nx: ");

    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);
    struct coordinates input;
    input.y = y;
    input.x = x;
    return input;
}

int is_on_board(int x, int y, int n, int m){

  if (0 <= x && x < n && 0 <= y && y < m)
    return 1;

  else
    return 0;
}

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

void initialize_fish(struct player players[], int pla){

    for(int i = 0; i < pla; i++){
        players[i].fish = 0;
    }
}

void collect_fish(int player_id, struct player* player, int i, int board[][N]){

    int x = player->penguin[i].x;
    int y = player->penguin[i].y;

    (player -> fish) += board[x][y];

    board[x][y] = player_id + 'A';
}

