#include <stdio.h>
#include "structures.h"
#include "setup.h"
#include "board.h"
#include "penguin.h"
#include "game.h"


int main(){

	int n, m, number_of_players, penguins_per_player;
	put_in_data(&n, &m, &number_of_players, &penguins_per_player);

	if(check_data(n, m, number_of_players, penguins_per_player) != 0) return 0;

	int board[N][N];
	initialize_board(n, m, board);
    create_board(n, m, number_of_players, penguins_per_player, board);

	struct player players[number_of_players];
    initialize_fish(players, number_of_players);
    place_penguins(n, m, number_of_players, penguins_per_player, players, board);

    play_game(n, m, number_of_players, penguins_per_player, players, board);
    evaluate_game(number_of_players, players);

	return 0;
}

