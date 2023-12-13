#include <stdio.h>
#include "move.h"
#include "penguin.h"

int is_available(int n, int m, int x, int y, int board[][N]){

    bool size_ok;
    //is on board nxm?
    if (x>n || y>m){
        printf("\n These coordinates are not in your board. Please try again.\n");
        size_ok==false;
        return 0;
    }
    else{
            size_ok=true;
    }
    //is not other penguin?
    if (size_ok==true && board [x][y]==-1){
        return 0;
    }
    //is not equal 0?
    else if (size_ok==true && board [x][y]==0){
        return 0;
    }
    else{
    return 1;//1 if available, 0 if not
    }
}

int can_penguin_move(int n, int m, struct coordinates penguin, int board[][N]){
   //first we save the coordinates of the penguin.
    int x=penguin.x;
    int y=penguin.y;
    //we create for variables for each of the possible four movements
    int up=0;
    int down=0;
    int left=0;
    int right=0;
    //we check the movements in the x axes
    up=is_available ( n, m, x+1, y, board);

    down=is_available ( n,  m, x-1, y, board);
    //we check the movement in the y axes
    left=is_available(n, m, x, y+1, board);
    right=is_available( n, m, x, y-1, board);

    //we check if any of the values is 1
    //problema: no entra en los if
    if (up==1){
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

    for (int i=0; i<pen; i++){//it is okay called to each of the penguins
        int penguinmove=0;
        penguinmove=can_penguin_move(n, m, player->penguin[i], board );//¿is okay used the struct?
        //if the penguin can move then we change the previous parameter
        if (penguinmove==1){
            return 1;
        }
         else{
        return 0;
        }//1 if any can, 0 if not
    }
}

int can_any_move(int n, int m, int pla, int pen, struct player players[], int board[][N]){
    bool any_move; // parameter to check if anyone can move a penguin
        for (int i=0; i<pla; i++){//it is okay called to each of the penguins
            int playermove;//parameter to check if the player can be moved

                playermove=can_player_move(n, m,pen, &players[i], board );//¿is okay used the struct?
        //if the penguin can move then we change the previous parameter
            if (playermove==1){
                return 1;
                }
            else{
                return 0;

            }//1 if any can, 0 if not
        }
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
    if(x==new_x || y==new_y){
        return 1;
        printf("ok\n");
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
                if(board[x][i]!=1 && board[x][i]!=2 && board[x][i]!=3){
                    return 0;
                }
            }
            return 1;
        }
        else{
           // printf("poruszasz sie w lewo");
            for(int i=y-1; i>=new_y; i--){
                //printf("x: %d y: %d\n",x,y);
                if(board[x][i]!=1 && board[x][i]!=2 && board[x][i]!=3){
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
                if(board[i][y]!=1 && board[i][y]!=2 && board[i][y]!=3){
                    return 0;
                }
            }
            return 1;
        }
        else{
          //  printf("poruszasz sie w gore");
            for(int i=x-1; i>=new_x; i--){
           //     printf("x: %d y: %d\n",x,y);
                if(board[i][y]!=1 && board[i][y]!=2 && board[i][y]!=3){
                    return 0;
                }
            }
            return 1;
        }
    }
}

int can_move_there(int n, int m, int new_x, int new_y, struct coordinates penguin, int board[][N]){

    //is_on_board?
    //is_grid_line?
    //check_move
     if(is_on_board(new_x,new_y,n,m)==1 && is_grid_line(penguin.x,penguin.y,new_x,new_y)==1 && check_move(penguin.x, penguin.y, new_x, new_y, board)==1){
        return 1;
    }else{
        return 0;
    }
    //1 if the move is valid, 0 if it isn't
}





