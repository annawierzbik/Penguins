#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "board.h" //not necessary, used only to display board for testing
#include "auto.h"

int main(int argc, char *argv[]){

    char my_ID[MAX_LINE_LENGTH] = "igf";
    char enemy_ID[MAX_LINE_LENGTH] = "igf";
    int penguins = 0, phase = -1, name = 0, input_ID = -1, output_ID = -1;
    int rows = 0, columns = 0, number_of_players;

    if(!interpret(argc, argv, &phase, &penguins, &name, &input_ID, &output_ID)) return 3;
    if(name){ printf("%s\n", my_ID); return 0; }

    int board[N][N];
    struct player players[P];

    if(!read_file(argv, input_ID, board, players, &number_of_players, &rows, &columns)) return 2;
    int my_number = identify(my_ID, players, &number_of_players);
    int enemy_number = identify(enemy_ID, players, &number_of_players);

    int result = 3;

#ifdef DEBUG
    display_board(rows, columns, board);
#endif

    if(phase == 0) result = placement(columns, rows, penguins, &players[my_number], my_number,enemy_number, board);
    else if (phase == 1) result = movement(columns, rows, penguins, board, my_number, &players[my_number]);

#ifdef DEBUG
    if(result != 3) display_board(rows, columns, board);
#endif

    if(!write_file(argv, output_ID, board, players, number_of_players, rows, columns)) return 2;
    return result;
}
