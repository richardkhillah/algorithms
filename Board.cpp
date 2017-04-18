/** @file Board.cpp
 *  @brief Implementation file for Board.h.
 *
 *  Refer to Board.h for function descriptions.
 *
 *  @author Richard Khillah
 *  @bugs No known bugs.
 */

#include "Board.h"
#include <string>
#include <iostream>
using namespace std;


Ship* Board::generateShipWithLength(int l) {
  Ship *s;

  /* Generate an x and y */
  int x = rand() % 10 + 1;
  int y = rand() % 10 + 1;

  /* generate 1 for Horizontal or 2 for Vertical */
  switch ((rand() % 2 )+ 1) {
    /* HORIZONTAL */
    case 1:
      /* Make sure the origional x-coordinate plus length
       * fits on board.  If it doesn't, generate a new
       * x-coordinate.
       */
      while (x+l > 10 || x == 0){
        x = rand() % (10 - l);
      }

      /* create a ship with given parameters */
      s = new Ship(point(x,y), HORIZONTAL, l);

      /* Make sure no other ship will coincide with
       * ship.
       */
      for (int i = 2; i < l; i++) {
        while (ships[i-2]->collidesWith(*s)) {
          /* delete the ship that collides with a
           * previously created ship
           */
          delete s;
          /* generate a new ship */
          x = rand() % (10-l);
          s = new Ship(point(x,y), HORIZONTAL, l);
        }
      }
      break;

    /* VERTICAL */
    case 2:
      /* Generate Vertical ship similarly as Horizontal */
      while (y+l > 10 || y == 0) {
          y = rand() % (10-l);
      }
      /* Create a new ship object */
      s = new Ship(point(x,y), VERTICAL, l);

      for (int i = 2; i < l; i++) {
        while (ships[i-2]->collidesWith(*s)) {
          /* delete the ship that collides with a
           * previously created ship
           */
          delete s;
          /* generate a new ship */
          y = rand()%(10-l);
          s = new Ship(point(x,y), VERTICAL, l);
        }
      }
      break;
  } // end switch

  return s;
}

Board::Board(){
  for (int i = 0; i < 4; i++)
    ships[i] = generateShipWithLength(i+2);
}

bool Board::fireShot(int x, int y) {
  /* check all cycle through all ships */
  for (int i = 0; i < 4; i++) {
    /* if a ship is hit at point (x, y) */
    if (ships[i] -> containsPoint(point(x,y))) {

      /* add (x, y) to hits */
      ships[i] -> shotFiredAtPoint(point(x,y));
      /* let the user know s/he sunk a ship of size getLength() */
      if (ships[i] -> isSunk())
        cout << "You sunk a ship of length " << ships[i]->getLength() << endl;

      return true;
    }
  }

  /* otherwise add point to misses */
  misses.add(point(x,y));
  return false;
}

int Board::unsunkShipCount(){
  int count = 0;

  for(int i = 0; i < 4; i++)
    if (!(ships[i] -> isSunk()))
      count++;

  return count;
}

void Board::display(){

  bool ship = false;
  bool miss = false;
  bool containsPt = false;
  bool isHit = false;

  /* for each row ... */
  for (int y = 10; y >=0; y--) {
    /* formatting */
    if (y == 0) {
        for (int i = 0; i < 10; i++)
            cout << "\t" << i;
        cout << endl;
    }

    else {
      /* display each column */
      for (int x = 0; x < 11; x++) {
        /* formatting */
        if (x == 0)
          cout << y-1 << "\t";

        else {
          ship = false;
          miss = false;
          if (misses.contains(point(x-1,y-1)))
            miss = true;

          /* check wheter ships ship has been hit */
          for (int s = 0; s < 4 && miss == false; s++) {
            containsPt = ships[s]->containsPoint(point(x-1,y-1));
            isHit = ships[s]->isHitAtPoint(point(x-1,y-1));
            ship = (ship && isHit) ? true : false;
          }

          /* print out the board. if miss, print `.',
           * if hit, print `X', otherwise print `~'
           */
          (miss) ? cout << ".\t" : ((ship) ? cout << "X\t" : cout << "~\t");
        }

        /* formatting */
        if (x == 10) { cout << endl << endl; }
      }
    }
  }
} // end display()
