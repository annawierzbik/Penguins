#include <stdio.h>
#include "move.h"

void makeMove(struct Board *board, int *ROW , int *COLUMN) {
    char direction;
    printf("Introduce where do you wanna move the oenguin (u/d/l/r): ");
    scanf(" %c", &direction);

    int newrow = *ROW;
    int newcolumn = *COLUMN;

    // changing the position of the fish 
    switch (direction) {
        case 'u':
            if (newrow > 0) {
                newrow--;
            }
            break;
        case 'd':
            if (newrow < 99) {
                newrow++;
            }
            break;
        case 'l':
            if (newcolumn > 0) {
                newcolumn--;
            }
            break;
        case 'r':
            if (newcolumn < 99) {
                newcolumn++;
            }
            break;
        default:
            printf("not valid direction. Try again.\n");
            return;
    }

    // Check is the new position is available
    if (    board->cells[nuevaFila][nuevaColumna] == ' ') {
        // if it is free, change to the new position
        board->cells[*ROW][*COLUMN] = ' ';
        board->cells[nuevaFila][nuevaColumna] = 'X'; // Suposing that the  fish 'X'. this how i have tested, it should change to the player.
        *ROW = nuevaFila;
        *COLUMN = nuevaColumna;
    } else {
        printf("The place is not available. Try again.\n");
    }
}
// this function is only for the movement of the penguin, it should be used after we have checked that the penguin can move. in case there is no posible movement it will tell you. to indicate where do you wanna place the penguins i have thought of indicating it using u(UP), d (down), l(LEFT), r(RIGHT).

void move_penguin(){
	//choose penguin
	//if penguin cannot move go back to: choose penguin
	// (possibly) display/highlight all the possible moves for the penguin
	//choose coordinates
	//check if coordinates are valid
	//(if they were anomg the ones displayed earlier)
	//if not go back to: choose penguin
	//else change coordinates
	//collect fish
	//change value of the current floe to -1
}
