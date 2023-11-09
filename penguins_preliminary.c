#include <stdio.h>
const int N = 1000000;
int board[N][N];

struct coordinates{
	int x;
	int y;
};

struct player{
	int fish;
	struct coordinates penguin[N];
	int penguin_number = 0;
};


// player[1].penguin[0].x

void create_board(int n, int m){
	//creates board with dimensions n, m
	//fills in board randomly with:
	//-1 - sea / eliminated ice floe
	// 1, 2, 3 - ice floe with fish on it
}

void place_penguin(){
	//insert coordinates of a penguin
	//check if valid
	//coordinates on board
	//value is 1
	//if not go back to: insert coordinates of a penguin
	//set the coordinates of the penguin
	//change value of the floe to -1
}

void move_penguin(){
	//choose penguin
	//if penguin cannot move go back to: choose penguin
	//display all the possible moves for the penguin
	//choose coordinates
	//check if coordinates are valid
	//(if they were anomg the ones displayed earlier)
	//if not go back to: choose penguin
	//else change coordinates
	//collect fish
	//change value of the current floe to -1
}

int main(){
	
	//SETUP PHASE
	
	//insert board measurements, number of players and penguins
	
	//check if user input is valid
	
	do{
		create_board(n, m);
	}while(number_of_players * number_of_penguins <= /*a function counting the ones on the board*/);
	
	//place the penguins
	
	struct player current_player[number_of_players];
	
	for(int i = 0; i < number_of_penguins; i++){
		for(int j = 0; j < number_of_players; j++){
			place_penguin(&current_player[j].penguin[i]);
		}
	}
	
		
	
	//MOVEMENT PHASE
	
	while(/*any of the players can move*/){
		
		if(/*player can move*/) move_penguin();
		//change player
	}
	
	
	//EVALUATION PHASE
	
	
	
	//sort the players by number of fish
	//if any player has more fish than any other display the winner
	//else declare a tie
	//display the results of each player
	
	return 0;
}
