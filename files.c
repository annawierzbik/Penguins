#include <stdlib.h>
#include "files.h"
#include "board.h"

///________________________________________________COMMAND LINE MANAGEMENT______________________________________________

int interpret(int argc,char* argv[],int* phase,int* penguins,int* name, int* input_ID, int* output_ID){
    if (argc < 2)
    {
        printf("Error - Incorrect input parameters.\n");
        printf("Correct program invocations are as follows:\n");
        printf("penguins.exe phase=placement penguins=<natural number> <input board file> <output board file>");
        printf("\npenguins.exe phase=movement <input board file> <output board file>");
        printf("\npenguins.exe name");

        return 0;
    }
    for(int i = 1; i < argc && i < MAX_NUM_PARAMS; i++){
        if(strcmp("phase=placement", argv[i]) == 0) *phase = 0;
        else if(strcmp("phase=movement", argv[i]) == 0) *phase = 1;
        else if(strcmp("name", argv[i]) == 0) *name = 1;
        else if(strncmp("penguins=", argv[i], 9) == 0) *penguins = penguins_no(argv[i]);
        else if(is_txt(argv[i]) && *input_ID==-1) *input_ID = i;
        else if(is_txt(argv[i]) && *input_ID!=-1) *output_ID = i;
        else{
            printf("Error - Cannot interpret command inputRow");
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

///__________________________________________________FILE MANAGEMENT__________________________________________________


int read_file(char* argv[], int input_ID, int board[N][N], struct player players[P], int* pla, int* rows, int* cols){

    int playerNumber = 0;
    char inputRow[MAX_LINE_LENGTH];

    if(input_ID == -1){ printf("No file name provided\n"); return 0;}
    FILE *input = fopen(argv[input_ID], "r");
    if(input == NULL){ printf("Input file cannot be opened\n"); return 0;}

    fscanf(input, "%d %d", rows, cols);

    for( int row = 0; row < *rows; row++){
        for(int col = 0; col < *cols; col++){
            int number;
            fscanf(input, "%d", &number);
            board[row][col] = number;
        }
    }

    fgets(inputRow, sizeof(inputRow), input); 

    char playerName[MAX_LINE_LENGTH];
    int playerNum, playerFish;

    while(fscanf(input, "%s %d %d\n", playerName, &playerNum, &playerFish) != EOF){

        playerNumber++;
        players[playerNumber].fish = playerFish;
        strcpy(players[playerNumber].name, playerName);

            #ifdef DEBUG
            printf("PlayerName: %s, Id: %d, Fish: %d\n", playerName, playerNum, playerFish);
            #endif
    }

    *pla = playerNumber;
    fclose(input);
    return 1;
}

int identify(char* my_ID, struct player players[P], int* number_of_players){

    for(int i = 0; i <= *number_of_players; i++) {
        if(strcmp(players[i].name, my_ID) == 0) return i;
        
    }
    (*number_of_players) += 1;
    strcpy(players[*number_of_players].name, my_ID);
    players[*number_of_players].fish = 0;
    return *number_of_players;
}

int write_file(char* argv[], int output_ID, int board[N][N], struct player players[P], int pla, int rows, int cols){

    if(output_ID == -1){ printf("No file name provided for output\n"); return 0;}
    FILE *output = fopen(argv[output_ID], "w");
    if(output == NULL){ printf("Output file cannot be opened\n"); return 0;}

    fprintf(output, "%d %d\n", rows, cols);

    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            if(board[row][col] > 9) fprintf(output, "%d ", board[row][col]);
            else fprintf(output, "0%d ", board[row][col]);
        }
        fprintf(output, "\n");
    }

    for(int i = 1; i <= pla; i++){
        fprintf(output, "%s %d %d\n", players[i].name, i, players[i].fish);
    }

    fclose(output);
    return 1;
}
