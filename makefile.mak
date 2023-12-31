#
# Make file for 
#
debug-auto: build-auto
	gdb play.exe

debug-inter: build-inter
	gdb play.exe

build-auto: clean
	gcc -g -Wall main_autonomous.c auto.c setup.c board.c game.c penguin.c move.c -o play

build-inter: clean
	gcc -g -Wall main_interactive.c setup.c board.c game.c penguin.c move.c -o play

deploy-auto:
	gcc -Wall main_autonomous.c setup.c board.c auto.c game.c penguin.c move.c -o play

deploy-inter:
	gcc -Wall main_interactive.c setup.c board.c auto.c game.c penguin.c move.c -o play

clean:
	del /Q play.exe

run-auto: deploy-auto
	play.exe

run-inter: deploy-inter
	play.exe