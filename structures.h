#ifndef _CONSTANTS_

#define N 26
#define P 15

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
};

#endif // _STRUCTURES_

