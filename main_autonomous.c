#include <stdio.h>
#include "structures.h"
#include "board.h" //not necessary, used only to display board for testing
#include "auto.h"

int main(int argc, char *argv[]){

    char* my_ID = "wbefpq";
    int penguins = 0, phase = -1, name = 0, input_ID = 0, output_ID = 0;
    if(!interpret(argc, argv, &phase, &penguins, &name, &input_ID, &output_ID)) return 3; //if an error occurs while interpreting

    if(name){
        printf("%s\n", my_ID);
        return 0;
    }

    int board[N][N];
    struct player players[P];
    int my_number = -1;
    if(!read_file(argv, input_ID, board, players, my_ID, &my_number)) return 2; //if an error occurs while reading the file

    int result = 3; //We assume that there might be a situation when phase is not specified or read incorrectly. That is an error.
    if(phase == 0) result = placement(penguins, &players[my_number], board);
    else if (phase == 1) result = movement(&players[my_number], board);

    if(!write_file(argv, output_ID, board, players)) return 2; //if an error occurs while writing the file
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
