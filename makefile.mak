#
# Make file for 
#
run-auto: deploy-auto
	penguins.exe phase=placement penguins=2 board-example-initial.txt board-example-result.txt

run-inter: deploy-inter
	penguins.exe

debug-auto: build-auto
	gdb penguins.exe phase=placement penguins=2 board-example-initial.txt board-example-result.txt

debug-inter: build-inter
	gdb penguins.exe

build-auto: clean
	gcc -g -Wno-return-type -DAUTO -DDEBUG -Wall main_autonomous.c auto.c setup.c board.c game.c penguin.c move.c -o penguins

build-inter: clean
	gcc -g -Wall main_interactive.c setup.c board.c game.c penguin.c move.c -o penguins

deploy-auto:
	gcc -Wall main_autonomous.c setup.c board.c auto.c game.c penguin.c move.c -o penguins

deploy-inter:
	gcc -Wall main_interactive.c setup.c board.c auto.c game.c penguin.c move.c -o penguins

clean:
	del /Q penguins.exe
	del /Q board-example-result.txt
	del /Q build\Testmain.out
	del /Q build\objs\*

test:
#	-I. makes sure all header files are included in compilation in the current directory (the same for -IUnity-master/src/)
#	here we compile all the files necesary to test our functions and put them into the catalog 
	gcc -c -I. -IUnity-master/src/ main_autonomous.c -o build/objs/main_autonomous.o
	gcc -c -I. -IUnity-master/src/ auto.c -o build/objs/auto.o
	gcc -c -I. -IUnity-master/src/ game.c -o build/objs/game.o
	gcc -c -I. -IUnity-master/src/ move.c -o build/objs/move.o
	gcc -c -I. -IUnity-master/src/ board.c -o build/objs/board.o
	gcc -c -I. -IUnity-master/src/ penguin.c -o build/objs/penguin.o
	gcc -c -I. -IUnity-master/src/ tests/Testmain.c -o build/objs/Testmain.o
	gcc -c -I. -IUnity-master/src/ Unity-master/src/unity.c -o build/objs/unity.o
	gcc -o build/Testmain.out build\objs\Testmain.o build\objs\move.o build\objs\board.o build\objs\auto.o build\objs\penguin.o build\objs\game.o build/objs/unity.o
	./build/Testmain.out