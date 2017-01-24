/*  Board.h might look something like this: */

#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
#include "Point.h"
#include "PointCollection.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
class Board{
private:
    Ship *ships[4];
    PointCollection misses;
    
    Ship* generateShipWithLength(int l);
    
public:
    Board();
    bool fireShot(int x, int y);
    int unsunkShipCount();
    void display();
};

#endif BOARD_H