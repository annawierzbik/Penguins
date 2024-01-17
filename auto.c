#include <stdlib.h>
#include "auto.h"
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


///__________________________________________________PLACEMENT FUNCTIONS________________________________________________


int placement(int cols, int rows, int penguins, struct player* my_player, int my_number, int board[N][N]){

    int penguinsPlaced = count_my_penguins(cols, rows, board, my_number);

    if(penguinsPlaced == 0) my_player->fish = 0;
    if (penguinsPlaced == -1) {   printf("Error - incorrect board values.\n");    return 3;}
    if (penguinsPlaced > penguins) {  printf("Error - too many penguins on board.\n");     return 3;}

    else if (penguinsPlaced == penguins) {printf("\nAll penguins placed."); return 1;}
    else return place_penguin(cols, rows, board, my_number, penguinsPlaced, my_player);

    printf ("Error - placement failed.\n");
    return 3;
}

int count_my_penguins(int cols, int rows, int board[N][N], int my_number){

    int count=0;

    for (int row=0; row<rows; row++) {
        for (int col=0; col<cols; col++) {
            if (board[row][col]>30) { printf("Error - floe value too big (floe[%d][%d])(count_my_penguins())\n", row, col);  return -1;}
            else if (board[row][col]%10 == my_number) count++;
        }
    }
    return count;
}

int count_fish_around(int col, int row, int cols, int rows, int board[N][N]){
    int fishAround = 0;
    if (col-1>=0) fishAround+=board[row][col-1]/10;
    if (col+1<cols)  fishAround+=board[row][col+1]/10;
    if (row-1>=0) fishAround+=board[row-1][col]/10;
    if (row+1<rows)  fishAround+=board[row+1][col]/10;

    return fishAround;
}

int place_penguin(int cols, int rows, int board[N][N], int my_number, int penguinsPlaced, struct player* my_player){
    struct coordinates bestCoordinates;
    int bestFish=0;
    int placementFound = 0;

    printf("\n(placement) my number: %d", my_number);
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){

            if(board[row][col] == 10){

                int fishAround = count_fish_around(col, row, cols, rows, board);
                //printf("Coordinates [%d][%d] with %d fish around\n", col, row, fishAround);

                if(fishAround >= bestFish){
                    bestCoordinates.x = row;
                    bestCoordinates.y = col;
                    bestFish = fishAround;
                    placementFound = 1;
                }
            }
        }
    }

    if (placementFound) {
        my_player->fish += 1;
        my_player->penguin[penguinsPlaced] = bestCoordinates;
        board[my_player->penguin[penguinsPlaced].x][my_player->penguin[penguinsPlaced].y] = my_number;
        return 0;
    }

    else {
        printf("There are no available floes to place penguin on\n");
        return 3;
    }
}



///_________________________________________________MOVEMENT FUNCTIONS_________________________________________________


int movement(int cols, int rows, int penguins, int board[N][N], int my_number, struct player* my_player){
/* ZALACZ ZMIENNE */
   //pick a penguin that can make a move
   int p=0;
   for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            if(board[row][col]%10 == my_number){
                my_player->penguin[p].x=row;
                my_player->penguin[p].y=col;
                p++;
            }
        }
   }
    int whichPenguin=0;
    int mostFish=0;
    for(int i = 0; i < p; i++ ){
        int x = my_player->penguin[i].x;
        int y = my_player->penguin[i].y;
        //printf("nr and cord of peng: %d %d %d\n", i, x, y);
        if(count_fish_around(y, x, cols, rows, board)>0){
            whichPenguin = i;
        }
    }

   // printf("nr pingwina: %d\n", whichPenguin);
   // printf("cord of peng: %d %d\n", my_player->penguin[whichPenguin].x, my_player->penguin[whichPenguin].y);
    int x = my_player->penguin[whichPenguin].x;
    int y = my_player->penguin[whichPenguin].y;
    int newX=x+1;
    int newY=y;
    int error=0;
    int movex=0;
    int movey=0;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        int temp=board[newX][newY]/10;
        if(temp>mostFish){
            mostFish=temp;
            movex=newX;
            movey=newY;
            error++;
        }
    }
    newX=x-1;
    newY=y;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        int temp=board[newX][newY]/10;
         if(temp>mostFish){
            mostFish=temp;
            movex=newX;
            movey=newY;
            error++;
        }
    }
    newX=x;
    newY=y+1;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        int temp=board[newX][newY]/10;
         if(temp>mostFish){
            mostFish=temp;
            movex=newX;
            movey=newY;
            error++;
        }
    }
    newX=x;
    newY=y-1;
    if(newX>=0 && newX<rows && newY>=0 && newY<cols && (board[newX][newY]/10)!=0){
        int temp=board[newX][newY]/10;
         if(temp>mostFish){
            mostFish=temp;
            movex=newX;
            movey=newY;
            error++;
        }
    }
    //errorem sprawdzam czy udalo sie funkcji wejsc do jakiegos ifa, jesli nie to error jest 0 i wyskoczy blad funkcja zwroci 3
    if(error==0){
        printf("something went wrong\n");
        return 3;
    }
    else{
        my_player->penguin[whichPenguin].x = movex;
        my_player->penguin[whichPenguin].y = movey;
        my_player->fish += board[my_player->penguin[whichPenguin].x][ my_player->penguin[whichPenguin].y]/10;
        board[x][y] = 00;
        board[my_player->penguin[whichPenguin].x][ my_player->penguin[whichPenguin].y] = my_number;
        return 0;
    }
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

    fgets(inputRow, sizeof(inputRow), input); // this is so that it skips to the next line after reading the board

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

    for(int i = 0; i < *number_of_players; i++) {
        if(strcmp(players[i].name, my_ID) == 0) {
            printf("\n%s", players[i].name);
            return i;
        }
        printf("\n(identify) i: %d", i);
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
