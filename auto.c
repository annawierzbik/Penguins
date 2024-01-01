#include "auto.h"
#include "board.h"

int interpret(int argc,char* argv[],int* phase,int* penguins,int* name, int* input_ID, int* output_ID){

#ifdef DEBUG
    printf("\nInput parameters:\n");
    for (int i = 0; i < argc; i++)  {
        printf(">> Argument %d: %s", i, argv[i]);
    }
#endif
    if (argc < 2)
    {
        printf("\n\nIncorrect input parameters.\n");
        printf("Correct program invocations are as follows:\n");
        printf("penguins.exe phase=placement penguins=<natural number> <input board file> <output board file>");
        printf("\npenguins.exe phase=movement <input board file> <output board file>");
        printf("\npenguins.exe name");
    
        return 3;
    }
    for(int i = 1; i < argc; i++){
        if(strcmp("phase=placement", argv[i]) == 0) *phase = 0;
        else if(strcmp("phase=movement", argv[i]) == 0) *phase = 1;
        else if(strcmp("name", argv[i]) == 0) *name = 1;
        else if(strncmp("penguins=", argv[i], 9) == 0) *penguins = penguins_no(argv[i]);
        else if(is_txt(argv[i]) && *input_ID==0) *input_ID = i;
        else if(is_txt(argv[i]) && *input_ID!=0) *output_ID = i;
        else{
            printf("Cannot interpret command line");
            return 0;
        }
    }
    return 1;
}

int penguins_no(char* str){

    int res = 0, i = 9;

    while(str[i]>='0' && str[i]<='9'){
        res = res*10 + str[i]-'0';
        i++;
    }

    return res;
}

int is_txt(char* str){
    if(strstr(str, ".txt")) return 1;
    return 0;

}

int read_file(char* argv[], int input_ID, int board[N][N], struct player players[P], char* my_ID, int* my_number){

    FILE *input = fopen(argv[input_ID], "r");
    if(input == NULL){
        printf("Input file cannot be opened\n");
        return 0;
    }

    //read data from file and store it in structures
    //return 0 if any errors occur and print what went wrong
    //if any of player ID's match ours *my_number is the number of the player with that ID; else it stays the same (-1)

    fclose(input);
    return 1;
}

int write_file(char* argv[], int output_ID, int board[N][N], struct player players[P]){

    FILE *output = fopen(argv[output_ID], "w");

    //write all data in the file in the proper format
    //return 0 if any errors occur and print what went wrong
    fclose(output);
    return 1;
    }

int count_my_penguins(int n, int m, int board[N][N], int my_number)
{    
    int count=0;
    for(int i; i<n; i++)
    {
        for(int j; j<m; j++)
        {
            if (board[i][j]%10==my_number) count++;
        }
    }  
    return count;
}

int countFishAround(int x, int y, int n, int m, int board[N][N])
{
    int fishAround = 0;
    
    return fishAround;
}
int place_penguin(int n, int m, int board[N][N], int my_number, int penguinsPlaced, struct player* my_player )
{
    struct coordinates best;
    int bestFish=0;
    int placementFound = 0;

    for(int row=0; row<n; row++)
    {
        for(int col=0; col<m; col++)
        {
            if(board[row][col]==10)
            {
                int fishAround = 0;
                fishAround = countFishAround(row, col, n, m, board);
                if (fishAround>=bestFish)
                {
                    best.x =row;
                    best.y =col;
                    bestFish = fishAround;
                    placementFound = 1;
                }
            }
        }
    }
    if (placementFound) {
        my_player->penguin[penguinsPlaced] = best;
        board[my_player->penguin[penguinsPlaced].x][my_player->penguin[penguinsPlaced].y] = my_number;
        my_player->fish++;
        return 0;
    }
    return 3;
}


    //find coordinates for the penguin using an algorithm
    //check coordinates
    //place the penguin and collect the fish
    //return 0 if successful
    //return 1 if all penguins placed (the number of player's penguins is equal to penguins)
    //return 3 if error
int placement(int n, int m, int penguins, struct player* my_player, int my_number, int board[N][N]){
    //check if player has penguins to place 
    int penguinsPlaced = 0;
    penguinsPlaced = count_my_penguins(n,m, board, my_number);

#ifdef DEBUG
    printf("Player %d has %d penguins to place\n", my_number, penguins);
    printf("- counted penguins for player %d = %d\n", my_number, penguinsPlaced);
    printf("- penguins to place: %d", penguins - penguinsPlaced);
#endif

    if (penguinsPlaced>penguins) return 3; //some mistake must have happened
    else if (penguinsPlaced==penguins) return 1; //all penguins are placed on board
    else
    {
        return place_penguin(n, m, board, my_number, penguinsPlaced, my_player);   
    }
    return 3;
}

int movement(struct player* my_player, int board[N][N]){

    //pick a penguin that can make a move
    //find new coordinates for the penguin using an algorithm
    //check the validity of the move
    //move the penguin and collect the fish
    //return 0 if successful
    //return 1 if no penguin can move
    //return 3 if error

    return 0;
}
