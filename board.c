#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

/*
Create board NEEDS to be changed so that first it generates the coordinates for ones,
and enough of them to place all the penguins of each player. Only then it fills the remaining fields
with 0/1/2/3. Then, the functions ones_on_board and is_board_good will not be needed.
*/

//the function initialize_board is just to start our board with parameters received from the player
void initialize_board(int n, int m, int board[][N]){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          board[i][j] = 0;
        }
    }
}

//this function creates our board with random numbers from 0 to 3 in order to have the fishes. (0 means there is an iceflow, 1,2 or 3 are the number of penguins there are)
void create_board(int n, int m, int board[][N]){
	srand(time(0));
    int num;
    //int board[n][m];
    for(int j=0; j<n; j++){
        //printf("\n");
        for (int i=0; i<m; i++) {
            num = rand() % 4 ;
            board[j][i]=num;
            //printf("%d ", board[j][i]);
        }
    }
	//creates board with dimensions n, m
	//fills in board randomly with:
	//0 - sea / eliminated ice floe
	// 1, 2, 3 - ice floe with fish on it
}

//we count the nomber of ones that exists in our board, to check if it is possible to play the game and place the penguins
int ones_on_board(int n, int m, int board[][N]){

    int ones = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(board[i][j] == 1) ones++;
        }
    }

    return ones;
}

//we check with the ones that we received from the previous function, the number of players multiplied by the number of pemguins should be bigger than the number of ones created randomly in the board
int is_board_good(int n, int m, int num, int pen, int board[][N]){

    if(num * pen <= ones_on_board(n, m, board)) return 1;
    else return 0;
}

// function to display our board
void display_board(int n, int m, int board[][N]){

    printf("\n\n    ");

    for(int i = 0; i < n; i++)  printf("%c ", i+'a');
    printf("\n    ");

    for(int i = 1; i < 2*n; i++)  printf("_");
    printf("\n");

    for(int j = 0; j < m; j++){

        if(j < 10)  printf(" %d |", j);
        else printf("%d |", j);

        for(int i = 0; i < n; i++){
            printf("%d ", board[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");
}
