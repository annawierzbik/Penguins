#
# Make file for 
#
run-auto: deploy-auto
	penguins.exe phase=placement penguins=2 board-example-initial.txt board-example-result.txt

run-inter: deploy-inter
	penguins.exe

debug-auto: build-auto
	gdb penguins.exe

debug-inter: build-inter
	gdb penguins.exe

build-auto: clean
	gcc -g -Wall main_autonomous.c auto.c setup.c board.c game.c penguin.c move.c -o penguins

build-inter: clean
	gcc -g -Wall main_interactive.c setup.c board.c game.c penguin.c move.c -o penguins

deploy-auto:
	gcc -Wall main_autonomous.c setup.c board.c auto.c game.c penguin.c move.c -o penguins

deploy-inter:
	gcc -Wall main_interactive.c setup.c board.c auto.c game.c penguin.c move.c -o penguins

clean:
	del /Q penguins.exe
	del /Q board-example-result.txt