#ifndef _CONSTANTS_

#define N 26
#define P 15
#define MAX_NUM_PARAMS 5
#define MAX_LINE_LENGTH 80

//so we can choose which version we want - autonomous or interactive (board is displayed differently etc.)
#define AUTO 1
//#undef AUTO

#define DEBUG 1
//#undef DEBUG

#endif // _CONSTANTS_

#ifndef _STRUCTURES_
#define _STRUCTURES_

struct coordinates{
    int x;
    int y;
};

struct player{
    int fish;
    struct coordinates penguin[P];
    char name[MAX_LINE_LENGTH];
};

#endif // _STRUCTURES_

