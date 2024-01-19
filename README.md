# epfu23W-A-penguins

Penguins - interactive and autonomous modes


This is the Penguins game - a simple game in which the goal is to collect as many fish as possible by moving your penguins on the board filled with floes with certain numbers of fish on them. The maximum size of the board is 26x26, and the maximum numbers of players and penguins per player are 15. 

First, all the players must place their penguins on the board. A penguin can only be placed on an existing floe with exactly one fish. Then, players move their penguins in turns. A turn consists of one player choosing one of their penguins (ommitted if the player has only one) and moving it from one floe to another. Penguins can only move along the grid lines, they cannot jump over empty floes or other penguins, and the floe the player wants to move their penguin to must have fish on it as well. The floe the penguin is leaving is cleared of fish and becomes an empty floe. The fish from the floe the penguin has been moved to are collected by the player. The game continues while any of the players can still make moves. When that is no longer, the player with the highest number of fish becomes the winner.

----> COMPILATION INSTRUCTIONS 
In order to compile and run the game in interactive mode please use these commands in the terminal:
    gcc main_interactive.c board.c game.c move.c penguin.c setup.c structures.h -o penguins.exe
    penguins.exe

In order to compile and run the game in autonomous mode please use these commands in the terminal:
    gcc main_autonomous.c auto.c files.c -o penguins.exe
    penguins.exe phase=placement penguins=<natural number> <input board file> <output board file>
    or
    penguins.exe phase=movement <input board file> <output board file>
    or
    penguins.exe name


This project is being made by:

Anna Kopyś,
Hanna Biegacz,
Anna Wierzbik,
Javier Terroba Oviedo