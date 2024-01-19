#
# Makefile for our program :)
#
#if you just type make this is the default command:
run-auto: build-auto
	penguins.exe phase=placement penguins=2 board-example-initial.txt board-example-result.txt

run-inter: build-inter
	penguins.exe

debug-auto: build-auto
	gdb penguins.exe phase=placement penguins=2 board-example-initial.txt board-example-result.txt

debug-inter: build-inter
	gdb penguins.exe

build-auto: clean
	gcc -g -Wall main_autonomous.c auto.c board.c files.c -o penguins

build-inter: clean
	gcc -g -Wall main_interactive.c setup.c board.c game.c penguin.c move.c -o penguins

clean:
# deleting unnecesary files
	del /Q penguins.exe
	del /Q board-example-result.txt
	del /Q build\Testmain.out
	del /Q build\objs\*

test:
#	-I. makes sure all header files are included in compilation in the current directory (the same for -IUnity-master/src/)
#	here we compile all the files necesary to test our functions and put them into the catalog 
	gcc -c -I. -IUnity-master/src/ main_autonomous.c -o build/objs/main_autonomous.o
	gcc -c -I. -IUnity-master/src/ auto.c -o build/objs/auto.o
	gcc -c -I. -IUnity-master/src/ files.c -o build/objs/files.o
	gcc -c -I. -IUnity-master/src/ board.c -o build/objs/board.o
	gcc -c -I. -IUnity-master/src/ tests/Testmain.c -o build/objs/Testmain.o
	gcc -c -I. -IUnity-master/src/ Unity-master/src/unity.c -o build/objs/unity.o
	gcc -o build/Testmain.out build\objs\Testmain.o build\objs\board.o build\objs\files.o build\objs\auto.o build/objs/unity.o
	./build/Testmain.out