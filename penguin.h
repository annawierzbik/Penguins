#include "structures.h"

struct coordinates put_in_coordinates();
int is_on_board(int, int, int, int);
int are_coordinates_good(struct coordinates, int, int, int [][N]);
void initialize_fish(struct player [], int);
void collect_fish(struct player*, int, int [][N]);
