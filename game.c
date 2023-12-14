#include <stdio.h>
#include "structures.h"
#include "game.h"
#include "board.h"
#include "move.h"
#include "penguin.h"

void place_penguins(int n, int m, int pla, int pen, struct player players[], int board[][N]){

    for (int i = 0; i < pen; i++) {
        for (int j = 0; j < pla; j++) {

            printf("\nPlayer %c places their penguin:", j+'A');
            display_board(n, m, board);

            do {
                players[j].penguin[i] = insert_coordinates(0);
            } while (are_coordinates_good(players[j].penguin[i], n, m, board) != 0);

            collect_fish(j, &players[j], i, board);
        }
    }
}

void move_penguin(int n, int m, int pen, int player_id, struct player* player, int board[][N]){

	int penguin_id;
	struct coordinates newc;

    do{
        do{
            penguin_id = choose_penguin(pen, player);
        } while(!can_penguin_move(n, m, player->penguin[penguin_id], board));

        newc = insert_coordinates(2);
    } while(!can_move_there(n, m, newc.x, newc.y, player->penguin[penguin_id], board));

    board[player->penguin[penguin_id].x][player->penguin[penguin_id].y] = 0;

    player->penguin[penguin_id].x = newc.x;
    player->penguin[penguin_id].y = newc.y;

	collect_fish(player_id, player, penguin_id, board);
}

void play_game(int n, int m, int pla, int pen, struct player players[], int board[][N]){

    int current = 0;

    while(can_any_move(n, m, pla, pen, players, board)){
        if(can_player_move(n, m, pen, &players[current], board)){

            printf("\nIt's player %c's turn:\n\n", current+'A');
            display_board(n, m, board);
            move_penguin(n, m, pen, current, &players[current], board);
        }
        else printf("\n\nPlayer %c cannot move anymore.", current + 'A');

        current = (current + 1) % pla;
    }
    printf("\n\n\nNo player can make a move anymore. This is the end of the game.\n");
}

  //for pla players finds the highest number of fish
  //players[i].fish - to access the fish of i-th player
  //if one player has more than the others declares the winner or else declares a tie

void evaluate_game(int pla, struct player players[]){
 
  struct player player_ranking[pla];
  int changes;
  char players_letter[pla];
    
  for (int i =0; i<pla-1; i++) {
    //initialize the ranking of players
    player_ranking[i]= players[i];
    //this array stores the letters associated with players
    players_letter[i] = 'A'+i;
    }
    
    //bubble sort the players by score

  do {
    changes = 0;
    for(int j = 0; j <pla; j++) {
          if(player_ranking[j+1].fish > player_ranking[j].fish) {        
          changes++;
          struct player temp = player_ranking[j];
          player_ranking[j] = player_ranking[j+1];
          player_ranking[j+1] = temp;
          char temp2 = players_letter[j];
          players_letter[j] = players_letter[j+1];
          players_letter[j+1] = temp2;  
        }
    }      
  } while (changes!=0);
  
  //print the ranking of players and their scores
  printf("\nTHE RANKING OF PLAYERS:\n");
  for(int k = 0; k <pla; k++) {
      printf("\tPlayer %c --- %d\n",players_letter[k], player_ranking[k].fish);   
  }
  
  if(player_ranking[0].fish == player_ranking[1].fish)
      printf("Its a draw!\n");
  
  
  else if (player_ranking[0].fish > player_ranking[1].fish)
      printf("Player %c won the game!\n", players_letter[0]);
}
