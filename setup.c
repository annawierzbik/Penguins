#include <stdio.h>
#include "setup.h"



//n, m - dimensions of the board
//pla - number of players
//pen - penguins per player

//lets the player put in the initial data
void put_in_data(int* n, int* m, int* pla, int* pen){


	printf("Insert the numbers of columns and rows in your board (max %d)\n", N);
	scanf("%d %d", n, m);

	printf("\nInsert the number of players (max %d)\n", P);
	scanf("%d", pla);

	printf("\nInsert the number of penguins per player (max %d)\n", P);
	scanf("%d", pen);
}


//n, m - dimensions of the board
//pla - number of players
//pen - penguins per player

//checks for all that can be wrong with data
int data_errors(int n, int m, int pla, int pen){

    if(n<=0 || m<=0 || pla<=0 || pen<=0)  return 1;
    if(n>N || m>N)  return 2;
    if(n*m <= pla*pen)  return 3;
    if(pla>P) return 4;
    if(pen>P) return 5;

	else return 0;
}


//n, m - dimensions of the board
//pla - number of players
//pen - penguins per player

//returns to the user info on what is wrong with their initial data
int check_data(int n, int m, int pla, int pen){

    int x = data_errors(n, m, pla, pen);

    if(x == 0) return 0;

    if(x == 1)
        printf("\nYour data does not meet the criteria. You can only use positive integers.\n");

    if(x == 2)
        printf("\nYour board is too big. The maximum size of the board is %d x %d.\n", N, N);

    if(x == 3)
        printf("\nThe board is too small to play a game with this many players and penguins per player.\n");

    if(x == 4)
        printf("\nThe number of players you have put in is too big. You can only play with up to %d players.\n", P);

    if(x == 5)
        printf("\nThe number of penguins per player you have put in is too big. Each player can only play with up to %d penguins.\n", P);

    printf("Run the game once more, choosing different starting data.\n\n");
    return x;
}
