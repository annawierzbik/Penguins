#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N = 1000000;
int board[N][N];

struct coordinates{
	int x;
	int y;
};

struct player{
	int fish;
	struct coordinates penguin[N]; //consider changing to a vector
};


// player[1].penguin[0].x


void put_in_data(int *n, int *m, int *pla, int *pen){


	printf("Insert the number of columns and rows in your board\n");
	scanf("%d %d", n, m);

	printf("\nInsert the number of players\n");
	scanf("%d", pla);

	printf("\nInsert the number of penguins per player\n");
	scanf("%d", pen);
}

int is_data_valid(int* n, int* m, int* pla, int* pen){

    if(*n * *m <= *pla * *pen){
		printf("\nThe board is too small to play a game with this many players and penguins per player.\n");
		printf("Run the game once more, choosing different starting data.\n\n");

		return 0;
	}

	else return 1;
}

void create_board(int n, int m){
	srand(time(0));
    int num;
    //int board[n][m];
    for(int j=0; j<n; j++){
        //printf("\n");
        for (int i=0; i<m; i++) {
            num = rand() % 4 ;
            board[j][i]=num;
            //printf("%d ", board[j][i]);
        }
    }
	//creates board with dimensions n, m
	//fills in board randomly with:
	//0 - sea / eliminated ice floe
	// 1, 2, 3 - ice floe with fish on it
}

int ones_on_board(int n, int m){
    
    int ones = 0;
    
    //counts the floes with value 1 on the board
    
    return ones;
}

int is_board_good(int n, int m, int num, int pen){
    
    if(num * pen <= ones_on_board(n, m)) return 1;
    else return 0;
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
	

	//insert board measurements, number of players and penguins per player

	int n, m, number_of_players, penguins_per_player;
	put_in_data(&n, &m, &number_of_players, &penguins_per_player);


	//check if user input is valid - if it is not, break the game

	if(is_data_valid(&n, &m, &number_of_players, &penguins_per_player) == 0) return 0;
	

	//create the board
	
	do{
		create_board(n, m);
	}while(is_board_good(n, m, number_of_players, penguins_per_player) == 0);
	

	//place the penguins
	
	struct player current_player[number_of_players];
	
	for(int i = 0; i < penguins_per_player; i++){
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
