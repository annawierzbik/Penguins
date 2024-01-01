#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"


void initialize_board(int n, int m, int board[][N]){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          board[i][j] = 0;
        }
    }
}

void create_board(int n, int m, int pla, int pen, int board[][N]){

	srand(time(0));

    int num, ones = pla * pen;

    for(int k = 0; k < ones; k++){

        int i = rand() % n;
        int j = rand() % m;

        board[i][j] = 1;
#ifdef DEBUG
        board[j][i] = 10;
#endif
    }

    for(int j = 0; j < n; j++){
        for (int i = 0; i < m; i++) {
            
            if(board[j][i] != 1){
                num = rand() % 4 ;
                board[j][i] = num;            
            }
        }
#ifdef DEBUG
        for (int i = 0; i < m; i++) {
            if(board[j][i] != 10){
                num = rand() % 4 ;
                board[j][i] = 10*num;            
            }
        }
#endif
    }
}

void display_board(int n, int m, int board[][N]){

    printf("\n\n    ");

    for(int i = 0; i < n; i++)  printf(" %c ", i+'a');
    printf("\n    ");

    for(int i = 1; i < 2*n; i++)  printf("__");
    printf("\n");

    for(int j = 0; j < m; j++){

        if(j < 10)  printf(" %.2d |", j);
        else printf("%.2d |", j);

        for(int i = 0; i < n; i++){
            if(board[i][j] >= 'A') printf(" %c ", board[i][j]);
            else printf("%.2d ", board[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");
}
