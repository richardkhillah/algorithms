# Battleship

Play a game of battleship!
Description:
This game of battleship works exactly the way you know battleship to work, except
your oponent is the computer. No need to place ships.. all there is to do is guess
where the computer has generated ships by entering coordinates.

Once you start the game, the game will continue until either you have sunk all
the ships or you type command `C-x' to exit.

##Key:
'~' : open water. use the x-y-axies in making your choice
'.' : miss. upon entering a coordinate, you miss if there is no ship at the entered
      location.
'X' : hit. If there is a ship at the x, y point you chose, then you have hit the ship.

There are 4 ships:
ship1 : length 2
ship2 : length 3
ship3 : length 4
ship4 : length 5

##To Play:
`battleship' is the precompiled executable of this game. To run the executable,
download `battleship', open a terminal/command-prompt window, cd to the directory
you downloaded to and run the following command
$ ./battleship

If you would like to compile the executable for yourself, by all means do so.
The following command will generate the same executable as provided.
$ g++ -std=c++11 -Wall -Wextra -Werror *.cpp -o battleship

You can generate a faster version, by perhaps compiling as follows
$ g++ -std=c++11 -Wall -Wextra -Werror -O2 *.cpp -o battleship


