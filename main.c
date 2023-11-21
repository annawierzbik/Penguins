#include <stdio.h>
#include "structures.h"
#include "setup.h"
#include "board.h"
#include "penguin.h"
#include "move.h"


int main(){

	//SETUP PHASE

	int n, m, number_of_players, penguins_per_player;
	put_in_data(&n, &m, &number_of_players, &penguins_per_player);

	if(check_data(n, m, number_of_players, penguins_per_player) != 0) return 0;


	int board[N][N];
	initialize_board(n, m, board);

	//here only create_board instead of the loop when the ones are ensured
	do{
		create_board(n, m, board);
	}while(is_board_good(n, m, number_of_players, penguins_per_player, board) == 0);


	struct player players[number_of_players];
    initialize_fish(players, number_of_players);

    //we can put the next lines (whole loop) in a function
    //place_penguins(n, m, number_of_players, penguins_per_player, board, players);
    //it will

    for (int i = 0; i < penguins_per_player; i++) {
        for (int j = 0; j < number_of_players; j++) {

            display_board(n, m, board);

            printf("\nPlayer %c places their penguin:\n\n", j+'A');

            do {
                players[j].penguin[i] = put_in_coordinates();

            //was: put_in_coordinates(&player[j].penguin[i]);
            //as the function returns the coordinates and does not modify the existing penguin we need this line to be
            //player[j].penguin[i] = put_in_coordinates();

            } while (are_coordinates_good(players[j].penguin[i], n, m, board) != 0);

            collect_fish(&players[j], i, board);
        }
    }



	//MOVEMENT PHASE

//	while(/*any of the players can move*/){

//		if(/*player can move*/) move_penguin();
		//change player
//	}


	//EVALUATION PHASE



	//sort the players by number of fish
	//if any player has more fish than any other display the winner
	//else declare a tie
	//display the results of each player

	return 0;
}

