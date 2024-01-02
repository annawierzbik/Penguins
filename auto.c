#include <stdlib.h>
#include "auto.h"
#include "board.h"

int interpret(int argc,char* argv[],int* phase,int* penguins,int* name, int* input_ID, int* output_ID){
    if (argc < 2)
    {
        printf("\n\nIncorrect input parameters.\n");
        printf("Correct program invocations are as follows:\n");
        printf("penguins.exe phase=placement penguins=<natural number> <input board file> <output board file>");
        printf("\npenguins.exe phase=movement <input board file> <output board file>");
        printf("\npenguins.exe name");
    
        return 3;
    }
    for(int i = 1; i < argc && i < MAX_NUM_PARAMS; i++){
        if(strcmp("phase=placement", argv[i]) == 0) *phase = 0;
        else if(strcmp("phase=movement", argv[i]) == 0) *phase = 1;
        else if(strcmp("name", argv[i]) == 0) *name = 1;
        else if(strncmp("penguins=", argv[i], 9) == 0) *penguins = penguins_no(argv[i]);
        else if(is_txt(argv[i]) && *input_ID==0) *input_ID = i;
        else if(is_txt(argv[i]) && *input_ID!=0) *output_ID = i;
        else{
            printf("Cannot interpret command inputRow");
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
   
    //read data from file and store it in structures
    //return 0 if any errors occur and print what went wrong
    //if any of player ID's match ours *my_number is the number of the player with that ID; else it stays the same (-1)
int read_file(char* argv[], int input_ID, int board[N][N], struct player players[P], char* my_ID, int* my_number, int* row, int* col){
    int row_index = 0, col_index = 0;
    FILE *input = fopen(argv[input_ID], "r");
    char inputRow[MAX_LINE_LENGTH];
    int lineNumber = 0;
    int playerNumber = 0;

    if(input == NULL){    printf("Input file cannot be opened\n");    return 0;}
    row_index = 0;
    while (fgets(inputRow, sizeof(inputRow), input)) {
        // printf("Line: %s\n", inputRow);

        if (lineNumber == 0) {
            sscanf(inputRow, "%d %d", col, row);
            lineNumber++;
            continue;
        }
        
        if (lineNumber < *row) {    
            char *token = strtok(inputRow, " ");
            col_index = 0;
            while (token != NULL) {
                int number;
                if (sscanf(token, "%d", &number) != 1) {
                    break;
                }
                token = strtok(NULL, " ");
                board[col_index][row_index] = number;
                col_index++;
            }
        }

        if (lineNumber >= *row) {
            char playerName[MAX_LINE_LENGTH];
            int playerNum = 0;
            int playerFish = 0;
            sscanf(inputRow, "%s %d %d", playerName, &playerNum, &playerFish);
            //printf("Player: %s, Id: %d, Fish: %d\n", playerName, playerNum, playerFish);
            players[playerNumber].fish = playerFish;
            playerNumber++;
        }
        lineNumber++;
        row_index++;
    }
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

int count_my_penguins(int n_col, int n_row, int board[N][N], int my_number){    
    int count=0;
    for (int col=0; col<n_col; col++) {
        for (int row=0; row<n_row; row++) {
#ifdef DEBUG
            printf("Number on floe board[%d][%d]= %d is:  %d \n",col, row, board[row][col], board[row][col]%10);        
#endif
            if (board[row][col]>30) { printf("Error - floe value too big.\n");  return -1;}
            else if (board[row][col]%10 == my_number) {
                //printf("\nNumber = %d\n", board[col][row]%10);
                count++;
            }
        }
    }  
    return count;
}

int countFishAround(int x, int y, int n_col, int n_row, int board[N][N]) {
    int fishAround = 0;
        if (x-1>=0) fishAround+=board[y][x-1]/10;
        if (x+1<n_col)  fishAround+=board[y][x+1]/10;
        if (y-1>=0) fishAround+=board[y-1][x]/10;
        if (y+1<n_row)  fishAround+=board[y+1][x]/10;
    return fishAround;
}

int place_penguin(int n_col, int n_row, int board[N][N], int my_number, int penguinsPlaced, struct player* my_player ) {
    struct coordinates bestCoordinates;
    int bestFish=0;
    int placementFound = 0; //to make sure that the function found any floe to place the penguin

    for(int row=0; row<n_row; row++) {
        for(int col=0; col<n_col; col++) {
            if(board[col][row] == 10) {
                int fishAround = 0;
                fishAround = countFishAround(col, row, n_col, n_row, board);
                //printf("Coordinates [%d][%d] with %d fish around\n", col, row, fishAround);
                //if there are more fish around then previously - update bestCoordinates and bestFish
                if (fishAround>=bestFish){
                    bestCoordinates.x =col;
                    bestCoordinates.y =row;
                    bestFish = fishAround;
                    placementFound = 1;
                }
            }
        }
    }

    if (placementFound) {
        my_player->penguin[penguinsPlaced] = bestCoordinates; //place penguin
        board[my_player->penguin[penguinsPlaced].x][my_player->penguin[penguinsPlaced].y] = my_number; //change floe value
        my_player->fish++;
        return 0;
    }
    else printf("\nError - Did not place penguin. placementFound = %d\n", placementFound);
    return 3;
}

int placement(int n_col, int m, int penguins, struct player* my_player, int my_number, int board[N][N]) {
    int penguinsPlaced = 0;
    penguinsPlaced = count_my_penguins(n_col, m, board, my_number);

    if (penguinsPlaced == -1) {   printf ("Error - incorrect board values.");    return 3;}
    if (penguinsPlaced>penguins) {  printf("Error - too many penguins on board.\n");     return 3;} 
    else if (penguinsPlaced==penguins) {printf("All penguins are already placed on board.\n"); return 1;}
    else {
        return place_penguin(n_col, m, board, my_number, penguinsPlaced, my_player);
    }

#ifdef DEBUG
    printf("\nPlayer %d has %d penguins to place\n", my_number, penguins);
    printf("- penguins on board: %d\n", penguinsPlaced);
    printf("- penguins to place: %d\n\n", penguins - penguinsPlaced);
#endif
    
    printf("\nPlacement failed.\n"); //the function should always go into one of the categories earlier
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
