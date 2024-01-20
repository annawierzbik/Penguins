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

void find_my_penguins(int cols, int rows, int penguins, int board[N][N], int my_number, struct player* my_player){
    int p=count_my_penguins(cols,rows,board,my_number);
    for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            if(board[row][col]%10 == my_number){
                my_player->penguin[p].x=row;
                my_player->penguin[p].y=col;
            }
        }
   }
}

int can_move(int cols, int rows, int penguins, int board[N][N], int my_number, struct player* my_player){
    int p=count_my_penguins(cols,rows,board,my_number);
    int check=0;
    for(int i = 0; i < p; i++ ){
        int x = my_player->penguin[i].x;
        int y = my_player->penguin[i].y;
        if(count_fish_around(y, x, cols, rows, board)>0){
            check++;
        }
    }
    if(check==0){
        return 0;
    }
    else{
        return 1;
    }
}

int choose_penguin(int cols, int rows, int penguins, int board[N][N], int my_number, struct player* my_player){
    int p=count_my_penguins(cols,rows,board,my_number);
    int which=0;
    for(int i = 0; i < p; i++ ){
        int x = my_player->penguin[i].x;
        int y = my_player->penguin[i].y;
        if(count_fish_around(y, x, cols, rows, board)>0){
            which=i;
        }
    }
    return which;
}
int fish_right(int x, int y, int board[N][N], int cols, int rows){
    int newX=x+1;
    int newY=y;
    int value=0;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        value=board[newX][newY]/10;
    }
    return value;
}

int fish_left(int x, int y, int board[N][N], int cols, int rows){
    int newX=x-1;
    int newY=y;
    int value=0;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        value=board[newX][newY]/10;
    }
    return value;
}

int fish_up(int x, int y, int board[N][N], int cols, int rows){
    int newX=x;
    int newY=y+1;
    int value=0;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        value=board[newX][newY]/10;
    }
    return value;
}

int fish_down(int x, int y, int board[N][N], int cols, int rows){
    int newX=x;
    int newY=y-1;
    int value=0;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        value=board[newX][newY]/10;
    }
    return value;
}

int movement(int cols, int rows, int penguins, int board[N][N], int my_number, struct player* my_player){
    int p=count_my_penguins(cols,rows,board,my_number);
    if(p==0){
        printf("No penguins found\n");
        return 2;
    }
    find_my_penguins(cols, rows, penguins, board, my_number, my_player);
    if(can_move(cols, rows, penguins, board, my_number, my_player)){
        printf("None of the penguins can move\n");
        return 1;
    }
    int whichPenguin=choose_penguin(cols, rows, penguins, board, my_number, my_player);
    int x = my_player->penguin[whichPenguin].x;
    int y = my_player->penguin[whichPenguin].y;
    int error=0;
    int movex=0;
    int movey=0;
    int mostFish=0;
    int temp=fish_right(x,y,board,cols,rows);
    if(temp>mostFish){
        mostFish=temp;
        movex=x+1;
        movey=y;
        error++;
    }
    temp=fish_left(x,y,board,cols,rows);
    if(temp>mostFish){
        mostFish=temp;
        movex=x-1;
        movey=y;
        error++;
    }
    temp=fish_up(x,y,board,cols,rows);
    if(temp>mostFish){
        mostFish=temp;
        movex=x;
        movey=y+1;
        error++;
    }
    temp=fish_up(x,y,board,cols,rows);
    if(temp>mostFish){
        mostFish=temp;
        movex=x;
        movey=y-1;
        error++;
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

