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
#ifdef AUTO
        board[j][i] = 10;
         for(int j = 0; j < n; j++){
        for (int i = 0; i < m; i++) {
            if(board[j][i] != 10){
                num = rand() % 4 ;
                board[j][i] = 10*num;            
            }
        }
    }
#else
        board[i][j] = 1;
    for(int j = 0; j < n; j++){
        for (int i = 0; i < m; i++) {       
            if(board[j][i] != 1){
                num = rand() % 4 ;
                board[j][i] = num;          
            }
        }
    }
#endif
}
}

void display_board(int n, int m, int board[][N]){
    printf("\n\n    ");
#ifdef AUTO
    for(int i = 0; i < n; i++)  printf(" %c ", i+'a');
#else
    for(int i = 0; i < n; i++)  printf("%c ", i+'a');
#endif
    printf("\n    ");

#ifdef AUTO
    for(int i = 1; i < 2*n; i++)  printf("__");
#else
    for(int i = 1; i < 2*n; i++)  printf("_");
#endif
    printf("\n");

    for(int j = 0; j < m; j++){

#ifdef AUTO
        if(j < 10)  printf(" %.2d |", j);
        else printf("%.2d |", j);
#else
        if(j < 10)  printf(" %d |", j);
        else printf("%d |", j);
#endif 
        for(int i = 0; i < n; i++){
#ifdef AUTO
            if(board[i][j] >= 'A') printf(" %c ", board[i][j]);
            else printf("%.2d ", board[i][j]);
#else
            if(board[i][j] >= 'A') printf("%c ", board[i][j]);
            else printf("%d ", board[i][j]);
#endif
        }
        printf("\n");
    }
    printf("\n\n");
}
