#include <stdio.h>
#include "move.h"
#include "penguin.h"

int is_available(int n, int m, int x, int y, int board[][N]){

    //is on board nxm?
    if(!is_on_board(x, y, n, m)) return 0;

    //is not other penguin?
    if(board[x][y] >= 'A') return 0;

    //is not equal 0?
    if (board [x][y]==0) return 0;

    return 1;//1 if available, 0 if not

}

int can_penguin_move(int n, int m, struct coordinates penguin, int board[][N]){

    int x = penguin.x;
    int y = penguin.y;

    //we check if it can move to any adjacent floes
    //if it can't move there, it can't move at all
    if(is_available(n, m, x+1, y, board)
       || is_available(n, m, x-1, y, board)
       || is_available(n, m, x, y+1, board)
       || is_available(n, m, x, y-1, board)){
            return 1;
       }

    else return 0;//1 if it can move, 0 if it can't
}

int can_player_move(int n, int m, int pen, struct player* player, int board[][N]){

    for(int i = 0; i < pen; i++){
        if(can_penguin_move(n, m, player->penguin[i], board))   return 1;
    }

    return 0;//1 if any can, 0 if not
}

int can_any_move(int n, int m, int pla, int pen, struct player players[], int board[][N]){

    for(int i = 0; i < pla; i++){
        if(can_player_move(n, m, pen, &players[i], board)) return 1;
    }

    return 0;//1 if any can, 0 if not
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
            if(pen ==1)
            {
                return 0;
            }
            else
            {
            newc = insert_coordinates(1);
            }
        } while(which_penguin(newc.x, newc.y, pen, player) == -1);

    
    penguin_id = which_penguin(newc.x, newc.y, pen, player);
    return penguin_id;
}

int is_grid_line(int x, int y, int new_x, int new_y){
    if(x==new_x || y==new_y){
        return 1;
    }
    else{
        return 0;
    }
    //1 if true, 0 if not
}

int check_move(int x, int y, int new_x, int new_y, int board [][N]){
     //1 if no empty/occupied floes, 0 if there are
    if(x==new_x){
      //  printf("poruszasz sie poziomo");
        if(new_y>y){
           // printf("poruszasz sie w prawo");
            for(int i=y+1; i<=new_y; i++){
              //  printf("x: %d y: %d\n",x,y);
                if(!is_available(N, N, x, i, board)){
                    return 0;
                }
            }
            return 1;
        }
        else{
           // printf("poruszasz sie w lewo");
            for(int i=y-1; i>=new_y; i--){
                //printf("x: %d y: %d\n",x,y);
                if(!is_available(N, N, x, i, board)){
                    return 0;
                }
            }
            return 1;
        }
    }
     if(y==new_y){
       // printf("poruszasz sie pionowo");
        if(new_x>x){
            //printf("poruszasz sie w dol");
            for(int i=x+1; i<=new_x; i++){
               // printf("x: %d y: %d\n",x,y);
                if(!is_available(N, N, i, y, board)){
                    return 0;
                }
            }
            return 1;
        }
        else{
          //  printf("poruszasz sie w gore");
            for(int i=x-1; i>=new_x; i--){
           //     printf("x: %d y: %d\n",x,y);
                if(!is_available(N, N, i, y, board)){
                    return 0;
                }
            }
            return 1;
        }
    }
}

int can_move_there(int n, int m, int new_x, int new_y, struct coordinates penguin, int board[][N]){

    if(!is_on_board(new_x,new_y,n,m)){
        printf("The coordinates are not on the board. Try again.\n");
        return 0;
    }

    if(!is_grid_line(penguin.x,penguin.y,new_x,new_y)){
        printf("You can only move along the grid lines. Try again.\n");
        return 0;
    }

    if(!check_move(penguin.x, penguin.y, new_x, new_y, board)){
        printf("You cannot jump over empty floes or other penguins. Try again.\n");
        return 0;
    }

    return 1;
    //1 if the move is valid, 0 if it isn't
}





