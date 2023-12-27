#include "auto.h"

int interpret(int argc,char* argv[],int* phase,int* penguins,int* name, int* input_ID, int* output_ID){

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

int placement(int penguins, struct player* my_player, int board[N][N]){

    //find coordinates for the penguin using an algorithm
    //check coordinates
    //place the penguin and collect the fish
    //return 0 if successful
    //return 1 if all penguins placed (the number of player's penguins is equal to penguins)
    //return 3 if error

    return 0;
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
