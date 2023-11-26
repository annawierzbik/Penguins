#include <stdio.h>
#include "move.h"

void makeMove(struct Board *board, int *ROW , int *COLUMN) {
    char direction;
    printf("Ingrese la dirección del movimiento (u/d/l/r): ");
    scanf(" %c", &direction);

    int nuevaFila = *ROW;
    int nuevaColumna = *COLUMN;

    // Actualizar la posición de la ficha según la dirección ingresada
    switch (direction) {
        case 'u':
            if (nuevaFila > 0) {
                nuevaFila--;
            }
            break;
        case 'd':
            if (nuevaFila < 99) {
                nuevaFila++;
            }
            break;
        case 'l':
            if (nuevaColumna > 0) {
                nuevaColumna--;
            }
            break;
        case 'r':
            if (nuevaColumna < 99) {
                nuevaColumna++;
            }
            break;
        default:
            printf("Dirección no válida. Intente de nuevo.\n");
            return; // Salir de la función en caso de dirección no válida
    }

    // Verificar si la nueva posición está ocupada
    if (    board->cells[nuevaFila][nuevaColumna] == ' ') {
        // La nueva posición está libre, realizar el movimiento
        board->cells[*ROW][*COLUMN] = ' ';
        board->cells[nuevaFila][nuevaColumna] = 'X'; // Suponiendo que la ficha es 'X'
        *ROW = nuevaFila;
        *COLUMN = nuevaColumna;
    } else {
        printf("La posición está ocupada. Intente de nuevo.\n");
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
