#include <stdio.h>
#include "move.h"
#include "penguin.h"

int is_available(int n, int m, int x, int y, int board[][N]){

     bool size_ok;
    //is on board nxm?
    if (x<n || y<m){
        printf("\nThese coordinates are not in your board. Please try again.\n");
        size_ok=false;
        return 0;
    }
    else{
            size_ok=true;
    }
    //is not other penguin?
    if (size_ok==true && board [x][y]==players_letter[]){
        printf("\nThere is a penguin in this cell. Please try again.\n");
        return 0;
    }
    //is not equal 0?
    else if (size_ok==true && board [x][y]==0){
        printf("\nThere is an ice flow in this cell. Please try again.\n");
        return 0;
    }
    else{
    return 1;//1 if available, 0 if not
    }
}

int can_penguin_move(int n, int m, struct coordinates penguin, int board[][N]){
    //first we save the coordinates of the penguin.
    int x=input.x;
    int y=input.y;
    //we create for variables for each of the possible four movements
    int up, down, left, right;
    //we check the movements in the x axes
    up=is_available(int n, int m, int x+1, int y, int board[][N]);
    down=is_available(int n, int m, int x-1, int y, int board[][N]);
    //we check the movement in the y axes
    left=is_available(int n, int m, int x, int y+1, int board[][N]);
    right=is_available(int n, int m, int x, int y-1, int board[][N]);

    //we check if any of the values is 1
    if (up==1 || down==1 || left==1 || right==1){
        return 1;
    }
    else {
        return 0;
    }
//1 if it can move, 0 if it can't
}

int can_player_move(int n, int m, int pen, struct player* player, int board[][N]){
 bool playerok_move;// variable to check if there is a possibility of moving one of the penguins
    //we look for each of the penguins of a player if they can move

    for (int i=0; i<pen, i++){//it is okay called to each of the penguins
        int penguin;
        penguin=can_penguin_move(n, m, penguin[i], board [][N] )//¿is okay used the struct?
        //if the penguin can move then we change the previous parameter
        if (penguin==1){
            playerok_move==true;
        }
    }
//we check now if we have found a possible move or if there are no possible movements
    if (playerok_move==true){
        return 1;
    }
    else{
        return 0;
    }//1 if any can, 0 if not
    
}

int can_any_move(int n, int m, int pla, int pen, struct player players[], int board[][N]){

     bool any_move; // parameter to check if anyone can move a penguin
        for (int i=0; i<pla, i++){//it is okay called to each of the penguins
            int player;
                player=can_player_move(n, m,pen, player[i], board [][N] )//¿is okay used the struct?
        //if the penguin can move then we change the previous parameter
            if (player==1){
                any_move==true;
            }
        }
        if (any_move==true){
            return 1;
        }
        else{
            return 0;
        }//1 if any can, 0 if not
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





