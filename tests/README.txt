
----> HERE IS OUR DOCUMENTATION OF A MANUAL TESTS WE CONDUCTED FOR VARIOUS PARTS OF OUR CODE INCLUDING:
    - displaying the name of the player;
    - interpreting comand line parameters and reacting accordingly to incorrect input;
    - placement of the penguins and functions necesary for it to work correctly (count_my_penguins() and count_my_fish());
    - movement of the penguins;
    - writing the output file (as a part of either placement or movement test).

There also is a separate folder named "Full gameplay test" that shows the each one of the files created during a gameplay with two players.

NAME DISPLAY TEST:
    comand line input:
        gcc auto.c main_autonomous.c files.c -o Hania
        .\Hania.exe name
    expected:
        Hania
    output:
        Hania
    --- PASS ---

FUNCTION interpret()
    board file used is called board-example-initial-1.txt and looks like this:
    5 6
    00 10 20 30 10 20
    30 20 10 00 20 10
    30 00 20 10 00 30
    20 10 20 30 10 20
    00 00 20 03 20 30
    Hania 1 0
    Ania 2 0
    igft 3 1

    TEST 1:
        command used in the terminal: 
            gcc .\main_autonomous.c .\auto.c 
            .\a.exe phase=palcement penguins=3 .\board-example-initial.txt result.txt
        output:
            Error - Cannot interpret command inputRow
    --- PASS ---

    TEST 2:
        command used in the terminal: 
                gcc .\main_autonomous.c .\auto.c 
                .\a.exe phase=placement result.txt                           
        output:    
            Input file cannot be opened
    --- PASS ---
 
    TEST 3:
        command used in the terminal: 
            gcc .\main_autonomous.c .\auto.c .\board.c
            .\a.exe phase=placement                                      
        output:    
            No file name provided
            
    --- PASS ---
  
    TEST 4:
        command used in the terminal: 
            gcc .\main_autonomous.c .\auto.c .\board.c
            .\a.exe phase=placement penguins =-1 .\board-example-initial.txt result.txt
        output:
            Error - Cannot interpret command inputRow
    --- PASS ---

FUNCTION count_my_penguins()
    TEST 1:
        board
            00 10 20 30 10 20
            30 20 10 00 20 10
            30 00 20 10 00 30
            20 10 20 30 10 20
            00 00 20 03 20 30
        correct amount of penguins: 1
        function output: 1
    --- PASS ---

    TEST 2:
        board
            00 10 20 30 10 20
            03 02 10 00 00 10
            30 00 20 10 00 30
            20 03 20 30 10 20
            00 00 20 03 20 30
        correct amount of penguins: 3
        function output: 3
    --- PASS ---

    TEST 3:
        board
            00 10 20 30 10 20
            03 02 10 00 00 10
            70 00 20 10 00 30
            20 03 20 30 10 20
            00 00 20 03 20 30
        correct amount of penguins: -1 (Error - floe value too big (floe[0][2]))
        function output: -1
    --- PASS ---

FUNCTION count_fish_around()
    TEST 1:
            board
                00 10 20 30 10 20
                30 20 10 00 20 10
                30 00 20 10 00 30
                20 10 20 30 10 20
                00 00 20 03 20 30
            coordinates given to function: [0][1]
            corrct output: 7
            function output: 7
    --- PASS ---

    TEST 2:
            board
                00 10 20 30 10 20
                30 20 10 00 20 10
                30 00 20 10 00 30
                20 10 20 30 10 20
                00 00 20 03 20 30
            coordinates given to function: [0][3]
            corrct output: 4
            function output: 4
    --- PASS ---

    TEST 3:
            board
                00 00 20 30 10 20
                30 20 10 00 20 10
                30 00 20 10 00 30
                20 00 20 30 10 20
                00 00 20 03 20 30
            coordinates given to function: [3][2]
            corrct output: 5
            function output: 5
    --- PASS ---

FUNCTION placement() and write_file()
    TEST 1:
        input file:
            12 8
            00 10 20 30 10 20 02 30
            30 20 10 00 20 10 00 10
            30 00 20 10 10 30 00 20
            20 10 20 30 10 20 01 00
            00 00 20 10 20 30 30 30
            00 10 20 30 10 20 02 30
            30 20 10 00 20 10 00 10
            10 20 00 30 20 10 30 30
            30 10 20 00 00 30 20 10
            20 10 20 30 10 20 00 00
            00 00 20 10 20 30 30 30
            00 10 20 30 10 20 00 30
            Hania 1 1
            Ania 2 2
        output file:
            12 8
            00 10 20 30 10 20 02 30 
            30 20 10 00 20 10 00 10 
            30 00 20 10 10 30 03 20 
            20 10 20 30 10 20 01 00 
            00 00 20 10 20 30 30 30 
            00 10 20 30 10 20 02 30 
            30 20 10 00 20 10 00 10 
            10 20 00 30 20 10 30 30 
            30 10 20 00 00 30 20 10 
            20 10 20 30 10 20 00 00 
            00 00 20 03 20 30 30 30 
            00 10 20 30 10 20 00 30 
            Hania 1 1
            Ania 2 2
            igf 3 1
    player was aded to the list, penguin was placed on a field 10 with 10 fish around, points were aded
    file was written in the correct format, 
    --- PASS ---
    
    TEST 2:
    input file:
        12 8
        00 10 20 30 10 20 02 30
        30 20 10 00 20 10 00 10
        30 00 20 10 10 30 00 20
        20 10 20 30 10 20 01 00
        00 00 20 10 20 30 30 30
        00 10 20 30 10 20 02 30
        30 20 10 00 20 10 00 10
        10 20 00 30 20 10 30 30
        30 10 20 00 00 30 20 10
        20 10 20 30 10 20 00 00
        00 00 20 10 20 30 30 30
        00 10 20 30 10 20 00 30
        Hania 1 1
        Ania 2 2
        igf 3 14
    output file:
        12 8
        00 10 20 30 10 20 02 30 
        30 20 10 00 20 10 00 10 
        30 00 20 10 10 30 00 20 
        20 10 20 30 10 20 01 00 
        00 00 20 10 20 30 30 30 
        00 10 20 30 10 20 02 30 
        30 20 10 00 20 10 00 10 
        10 20 00 30 20 10 30 30 
        30 10 20 00 00 30 20 10 
        20 10 20 30 10 20 00 00 
        00 00 20 04 20 30 30 30 
        00 10 20 30 10 20 00 30 
        Hania 1 1
        Ania 2 2
        igf 3 14
        igf 4 1
    THE GAME DOESN"T SEE THAT HIS PLAYER ALREADY EXISTS (AND CONSEQUENTLY CORRECT HIS NUMBER OF FISH)
    AND MAKES A DUPLICATE
    --- FAIL ---
    after improving our code:
        12 8
        00 10 20 30 10 20 02 30 
        30 20 10 00 20 10 00 10 
        30 00 20 10 10 30 00 20 
        20 10 20 30 10 20 01 00 
        00 00 20 10 20 30 30 30 
        00 10 20 30 10 20 02 30 
        30 20 10 00 20 10 00 10 
        10 20 00 30 20 10 30 30 
        30 10 20 00 00 30 20 10 
        20 10 20 30 10 20 00 00 
        00 00 20 03 20 30 30 30 
        00 10 20 30 10 20 00 30 
        Hania 1 1
        Ania 2 2
        igf 3 1
    --- PASS ---

FUNCTION movement() and write file() 
    TEST 1:
        input file:
            5 6
            00 10 20 30 10 20 
            30 04 10 00 20 10 
            30 00 20 10 10 30 
            20 10 20 30 04 20 
            00 00 20 10 20 30 
            Hania 1 0
            Ania 2 0
            igft 3 1
            igf 4 1
        output file:
            5 6
            00 10 20 30 10 20 
            30 04 10 00 20 10 
            30 00 20 10 10 30 
            20 10 20 04 00 20 
            00 00 20 10 20 30 
            Hania 1 0
            Ania 2 0
            igft 3 1
            igf 4 4
        --- PASS ---
    TEST 2:
        input file:
            5 6
            00 10 00 00 00 20 
            30 20 02 00 01 00 
            30 00 20 10 00 00 
            20 10 00 00 00 02 
            00 00 01 00 00 00 
            Hania 1 15
            Anny 2 15
    
        output file:
            5 6
            00 10 00 00 00 20 
            30 20 00 00 01 00 
            30 00 00 02 00 00 
            20 10 00 00 00 02 
            00 00 01 00 00 00 
            Hania 1 15
            Anny 2 18
        --- PASS ---
    TEST 3:
        input file:
            input file:
            5 6
            00 00 00 00 00 00 
            00 01 00 00 00 00 
            00 00 00 00 00 00 
            00 00 00 00 00 00 
            00 00 01 00 00 00 
            Hania 1 15
            Anny 2 15
        output file:
            5 6
            00 00 00 00 00 00 
            00 01 00 00 00 00 
            00 00 00 00 00 00 
            00 00 00 00 00 00 
            00 00 01 00 00 00 
            Hania 1 15
            Anny 2 15
        "None of the penguins can move"
        --- PASS ---
    TEST 4:
        input file:
            5 6
            00 10 20 30 10 01 
            30 20 10 00 20 00 
            30 00 20 10 10 00 
            20 10 20 30 00 00 
            00 00 20 10 00 00 
            Hania 1 13
        expected action: penguin movement
        output : "error - chosen penguin cannot move"
        --- FAIL ---
    after fixing the issue (game did not consider turning right during movement):
        output file:
        --- PASS ---