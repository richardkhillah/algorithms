//
//  Board.cpp
//  Battleship
//

#include "Board.h"
#include <string>
#include <iostream>
using namespace std;

// Generate a ship object with the given length, and
// a random origin and orientation.
Ship* Board::generateShipWithLength(int l) {

    Ship *s;

    // Generate an x and y
    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;

    // generate 1 for Horizontal or 2 for Vertical
    switch ((rand() % 2 )+ 1) {
        // HORIZONTAL
        case 1:
            // Make sure the origional x-coordinate plus lenth
            // fits on board.  If it doesn't, generate a new
            // x-coordinate.
            while (x+l > 10 || x == 0){
                x = rand() % (10 - l);
            }

            // create a ship with given parameters
            s = new Ship(point(x,y), HORIZONTAL, l);

            // Make sure no other ship will cooincide with
            // ship.
            for (int i = 2; i < l; i++) {
                while (ships[i-2]->collidesWith(*s)) {
		  /* delete the origional ship */
		  delete s;
		  /* generate a new ship */
                  x = rand() % (10-l);
                  s = new Ship(point(x,y), HORIZONTAL, l);
                }
            }

            break;

        // VERTICAL
        case 2:
            // same algorithm as Horizontal
            while (y+l > 10 || y == 0) {
                y = rand() % (10-l);
            }
            s = new Ship(point(x,y), VERTICAL, l);

            for (int i = 2; i < l; i++) {
                while (ships[i-2]->collidesWith(*s)) {
		  /* delete the original ship */
		  delete s;
		  /* generate a new ship */
                  y = rand()%(10-l);
                  s = new Ship(point(x,y), VERTICAL, l);
                }
            }
            break;
    }

    return s;
}

// A constructor which creates four randomly placed and
// oriented ships and stores pointers to them into the
// ships array. The ships have the following lengths:
// 5, 4, 3, 2
Board::Board(){
    for (int i = 0; i < 4; i++) {
        ships[i] = generateShipWithLength(i+2);
    }
}

// Updates state to account for a shot at (x, y), i.e.
// if there is a ship at (x, y) the ship now knows it //ishitat(x,y). Ifthereisnoshipat(x,y)then
// the board has recorded this in its misses PointCollection

bool Board::fireShot(int x, int y) {
// create a temporary point to use in code
//    point temp(x, y);

    // check all cycle through all ships
    for (int i = 0; i < 4; i++) {
        // if a ship is hit at point (x, y)
        if (ships[i] -> containsPoint(point(x,y))) {
            // add (x, y) to hits
            ships[i] -> shotFiredAtPoint(point(x,y));
            // let the user know s/he sunk a ship of size getLength().
            if (ships[i] -> isSunk()) {
                cout << "You sunk a ship of length " << ships[i]->getLength() << endl;
            }

            return true;
        }
    }

    // otherwise add point to misses
    misses.add(point(x,y));
    return false;
}



// Returns the number of ships that have not yet been sunk
int Board::unsunkShipCount(){
    int count = 0;

    for(int i = 0; i < 4; i++) {
        if (!(ships[i] -> isSunk())) {
            count++;
        }
    }
    return count;
}
// Draws a grid display showing hits, misses and empty
// squares
void Board::display(){
    
    bool ship = false;
    bool miss = false;

    for (int y = 10; y >=0; y--) {
        // formatting
        if (y == 0) {
            for (int i = 0; i < 10; i++)
                cout << "\t" << i;
            cout << endl;
        }

        else {
            for (int x = 0; x < 11; x++) {
                // formatting
                if (x == 0) {
                    cout << y-1 << "\t";
                }

                else {
                    ship = false;
                    miss = false;
                    if (misses.contains(point(x-1,y-1))) {
                        miss = true;
                    }

                    for (int s = 0; s < 4 && miss == false; s++) {
                        if (ships[s]->containsPoint(point(x-1,y-1))) {
                            if (ships[s]->isHitAtPoint(point(x-1,y-1))) {
                                ship = true;
                            }
                        }
                    }

                    (miss) ? cout << ".\t" : ((ship) ? cout << "X\t" : cout << "~\t");
                }

                // formatting
                if (x == 10) { cout << endl << endl; }
            }
        }
    }
}
