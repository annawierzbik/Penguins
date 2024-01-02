#ifndef _CONSTANTS_

#define N 26
#define P 15

#endif // _CONSTANTS_

#ifndef _STRUCTURES_
#define _STRUCTURES_
//so we can choose which version we want - autonomous or interactive (board is displayed differently etc.)
#define AUTO 1
//#undef AUTO

#define DEBUG 1
//#undef DEBUG 

struct coordinates{
    int x;
    int y;
};

struct player{
    int fish;
    struct coordinates penguin[P];
};

#endif // _STRUCTURES_

