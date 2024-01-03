#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "board.h" //not necessary, used only to display board for testing
#include "auto.h"

int main(int argc, char *argv[]){

    char my_ID[MAX_LINE_LENGTH] = "igft";
    int penguins = 0, phase = -1, name = 0, input_ID = 0, output_ID = 0;
    int rows = 0, columns = 0, number_of_players;

    //if an error occurs while interpreting the file return error 3
    if(!interpret(argc, argv, &phase, &penguins, &name, &input_ID, &output_ID)) return 3;
    if(name){ printf("%s\n", my_ID); return 0; }

    int board[N][N];
    struct player players[P];

    //if an error occurs while reading the file return error 2
    if(!read_file(argv, input_ID, board, players, &number_of_players, &rows, &columns)) return 2;
    int my_number = identify(my_ID, players, &number_of_players);

    //We assume that there might be a situation when phase is not specified or read incorrectly. That is an error.
    int result = 3;

#ifdef DEBUG
    display_board(rows, columns, board);
#endif

    if(phase == 0) result = placement(columns, rows, penguins, &players[my_number], my_number, board);
    else if (phase == 1) result = movement(columns, rows, penguins, board, my_number, &players[my_number]);
//int cols, int rows,int penguins, int board[N][N], int my_number, struct player* my_player
#ifdef DEBUG
    if(result != 3) display_board(rows, columns, board);
#endif

    //if an error occurs while writing the file
    if(!write_file(argv, output_ID, board, players, number_of_players, rows, columns)) return 2;
    return result; //returns whatever the placement/movement operation returned
}



//This is the file for autonomous mode.
//BOTH THE INPUT AND THE OUTPUT, AS WELL AS WHAT IS RETURNED IN THIS FILE ARE
//SPECIFIED IN THE PENGUINS_V2 FILE IN TEAMS.
//It must be compatible with the specifications - pay attention to them.

//For this tutorial we need:
//command line parameters
//reading the state of the game from file ACCORDING TO SPECIFICATIONS
//writing the state of the game to file ACCORDING TO SPECIFICATIONS
