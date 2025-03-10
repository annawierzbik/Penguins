#include <stdio.h>
#include "penguin.h"

int getstring(char str[]){

    int i = -1;

    do{
        i++;
        str[i] = getchar();
    }while(str[i]!='\n' && i < P);

    if(i < 1)   return 0;

    return 1;
}

int fragment(char str[], char l, char r, int* i){

    int a = 0, s = 1;

    if(str[*i] == '-'){
        s = -1;
        (*i)++;
    }

    while (str[*i]>=l && str[*i]<=r){
        a = (r-l+1) * a + str[*i]-l;
        (*i)++;
    }

    return a*s;
}

int convert(char str[], int* x, int* y){

    int a = 0, b = 0, i = 0;

    b = fragment(str, '0', '9', &i);
    a = fragment(str, 'a', 'z', &i);
    if(b==0 && str[0]!='0') b = fragment(str, '0', '9', &i);

    if(str[i]!='\n'){
        printf("These are not proper coordinates. Try again.\n");
        return 0;
    }

    else{
        *x = a;
        *y = b;
        return 1;
    }
}

struct coordinates insert_coordinates(int type){

    struct coordinates input;
    char str[P];
    int cont;

    if(type == 0) printf("Insert the coordinates of the floe you want to place your penguin on:\n");
    if(type == 1) printf("Insert the coordinates of the penguin you want to move:\n");
    if(type == 2) printf("Insert the coordinates of the floe you want to move your penguin to:\n");

    do{
        cont = getstring(str);
    }while(!convert(str, &input.x, &input.y) || !cont);

    return input;
}

int is_on_board(int x, int y, int n, int m){

  if (0 <= x && x < n && 0 <= y && y < m)
    return 1;

  else
    return 0;
}


int are_coordinates_good(struct coordinates input, int n, int m, int board[][N]){

    int x = input.x;
    int y = input.y;

    if(!is_on_board(x, y, n, m)){
        printf("coordinates not on board. Try again\n");
        return 1;
    }

    if(board[x][y] != 1){
        printf("value of the floe is not 1. You can only place penguins on floes with value 1. Try again\n");
        return 2;
    }

    return 0;
}

void initialize_fish(struct player players[], int pla){

    for(int i = 0; i < pla; i++){
        players[i].fish = 0;
    }
}

void collect_fish(int player_id, struct player* player, int i, int board[][N]){

    int x = player->penguin[i].x;
    int y = player->penguin[i].y;

    (player -> fish) += board[x][y];

    board[x][y] = player_id + 'A';
}

