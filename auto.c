#include <stdlib.h>
#include "auto.h"
#include "board.h"

///__________________________________________________PLACEMENT FUNCTIONS________________________________________________


int placement(int cols, int rows, int penguins, struct player* my_player, int my_number, int board[N][N]){

    int penguinsPlaced = count_my_penguins(cols, rows, board, my_number);

    if(penguinsPlaced == 0) my_player->fish = 0;
    if (penguinsPlaced == -1) {   printf("Error - incorrect board values.\n");    return 3;}
    if (penguinsPlaced > penguins) {  printf("Error - too many penguins on board.\n");     return 3;}

    else if (penguinsPlaced == penguins) {printf("\nAll penguins placed."); return 1;}
    else return place_penguin(cols, rows, board, my_number, penguinsPlaced, my_player);

    printf ("Error - placement failed.\n");
    return 3;
}

int count_my_penguins(int cols, int rows, int board[N][N], int my_number){

    int count=0;

    for (int row=0; row<rows; row++) {
        for (int col=0; col<cols; col++) {
            if (board[row][col]>30) { printf("Error - floe value too big (floe[%d][%d])(count_my_penguins())\n", row, col);  return -1;}
            else if (board[row][col]%10 == my_number) count++;
        }
    }
    return count;
}

int count_fish_around(int col, int row, int cols, int rows, int board[N][N]){
    int fishAround = 0;
    if (col-1>=0) fishAround+=board[row][col-1]/10;
    if (col+1<cols)  fishAround+=board[row][col+1]/10;
    if (row-1>=0) fishAround+=board[row-1][col]/10;
    if (row+1<rows)  fishAround+=board[row+1][col]/10;

    return fishAround;
}

int place_penguin(int cols, int rows, int board[N][N], int my_number, int penguinsPlaced, struct player* my_player){
    struct coordinates bestCoordinates;
    int bestFish=0;
    int placementFound = 0;

    printf("\n(placement) my number: %d", my_number);
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){

            if(board[row][col] == 10){

                int fishAround = count_fish_around(col, row, cols, rows, board);
                //printf("Coordinates [%d][%d] with %d fish around\n", col, row, fishAround);

                if(fishAround >= bestFish){
                    bestCoordinates.x = row;
                    bestCoordinates.y = col;
                    bestFish = fishAround;
                    placementFound = 1;
                }
            }
        }
    }

    if (placementFound) {
        my_player->fish += 1;
        my_player->penguin[penguinsPlaced] = bestCoordinates;
        board[my_player->penguin[penguinsPlaced].x][my_player->penguin[penguinsPlaced].y] = my_number;
        return 0;
    }

    else {
        printf("There are no available floes to place penguin on\n");
        return 3;
    }
}



///_________________________________________________MOVEMENT FUNCTIONS_________________________________________________


int movement(int cols, int rows, int penguins, int board[N][N], int my_number, struct player* my_player){
   int p=0;
   for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            if(board[row][col]%10 == my_number){
                my_player->penguin[p].x=row;
                my_player->penguin[p].y=col;
                p++;
            }
        }
   }
    int whichPenguin=0;
    int mostFish=0;
    int can_move=0;
    for(int i = 0; i < p; i++ ){
        int x = my_player->penguin[i].x;
        int y = my_player->penguin[i].y;
        if(count_fish_around(y, x, cols, rows, board)>0){
            whichPenguin = i;
            can_move++;
        }
    }
    if(can_move==0){
        printf("None of the penguins can move\n");
        return 1;
    }
    int x = my_player->penguin[whichPenguin].x;
    int y = my_player->penguin[whichPenguin].y;
    int newX=x+1;
    int newY=y;
    int error=0;
    int movex=0;
    int movey=0;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        int temp=board[newX][newY]/10;
        if(temp>mostFish){
            mostFish=temp;
            movex=newX;
            movey=newY;
            error++;
        }
    }
    newX=x-1;
    newY=y;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        int temp=board[newX][newY]/10;
         if(temp>mostFish){
            mostFish=temp;
            movex=newX;
            movey=newY;
            error++;
        }
    }
    newX=x;
    newY=y+1;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        int temp=board[newX][newY]/10;
         if(temp>mostFish){
            mostFish=temp;
            movex=newX;
            movey=newY;
            error++;
        }
    }
    newX=x;
    newY=y-1;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        int temp=board[newX][newY]/10;
         if(temp>mostFish){
            mostFish=temp;
            movex=newX;
            movey=newY;
            error++;
        }
    }
    if(error==0){
        printf("error\n");
        return 3;
    }
    else{
        my_player->penguin[whichPenguin].x = movex;
        my_player->penguin[whichPenguin].y = movey;
        my_player->fish += board[my_player->penguin[whichPenguin].x][ my_player->penguin[whichPenguin].y]/10;
        board[x][y] = 00;
        board[my_player->penguin[whichPenguin].x][ my_player->penguin[whichPenguin].y] = my_number;
        return 0;
    }
}

