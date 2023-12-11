#include <stdio.h>
#include "move.h"
#include "penguin.h"

int is_available(int n, int m, int x, int y, int board[][N]){

    //is on board nxm?
    //is not equal 0?
    //is not other penguin?

    return 1;//1 if available, 0 if not
}

int can_penguin_move(int n, int m, struct coordinates penguin, int board[][N]){

    return 1;//1 if it can move, 0 if it can't
}

int can_player_move(int n, int m, int pen, struct player* player, int board[][N]){

    return 1;//1 if any can, 0 if not
}

int can_any_move(int n, int m, int pla, int pen, struct player players[], int board[][N]){

    return 1;//1 if any can, 0 if not
}

int which_penguin(int x, int y, int pen, struct player* player){
    
    //check if any of the players penguins in penuin[] matches the given x, y 
    for(int i =0; i<pen; i++){

        if(x == player->penguin[i].x && y == player->penguin[i].y) {
            //i the position in the array penguin[], so i={0, 1, ..., pen}
            return i;
        }
    }

    //if no penguins match given x, y:
    printf("\nThese coordinates do not match any of your penguins. Please try again.\n");
    return -1;
}

int choose_penguin(int pen, struct player* player){

    struct coordinates newc; // new coordinates
    int penguin_id;

    do{
        newc = insert_coordinates(1);
    } while(which_penguin(newc.x, newc.y, pen, player) == -1);

    
    penguin_id = which_penguin(newc.x, newc.y, pen, player);
    return penguin_id;
}

int is_grid_line(int x, int y, int new_x, int new_y){
    return 1;//1 if true, 0 if not
}

int check_move(int x, int y, int new_x, int new_y, int board [][N]){
    return 1;//1 if no empty/occupied floes, 0 if there are
}

int can_move_there(int n, int m, int new_x, int new_y, struct coordinates penguin, int board[][N]){

    //is_on_board?
    //is_grid_line?
    //check_move
    return 1;//1 if the move is valid, 0 if it isn't
}





