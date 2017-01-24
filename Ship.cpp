//
//  Ship.cpp
//  Battleship
//

#include "Ship.h"
#include <iostream>
using namespace std;

//*******************************************************************************************
// Constructor: creates ship of length l, starting at originPoint with o orientation
//*******************************************************************************************

Ship::Ship(point originPoint, direction d, int l) {
    origin = originPoint;
    length = l;
    orientation = d;
    
    if (d == HORIZONTAL) {
        for (int i = 0; i < l; i++) {
            points.add(point(originPoint.getX() + i, originPoint.getY()));
        }
    } else {
        for (int i = 0; i < l; i++) {
            points.add(point(originPoint.getX(), originPoint.getY() + i));
        }
    }
}

//*******************************************************************************************
// Copy constructor
//*******************************************************************************************

Ship::Ship(const Ship& s) {
     *this = s;
}

//*******************************************************************************************
// Returns true if a Ship covers a point on the board, false if not
//*******************************************************************************************

bool Ship::containsPoint(const point& p) const{
    return (points.contains(p) ? true : false);
}

//*******************************************************************************************
// Returns true if receiving ship shares a point with argument ship
//*******************************************************************************************

bool Ship::collidesWith(const Ship& s) const {
    
    for (int i = 0; i < s.points.getSize(); i++) {
        if (containsPoint(s.points[i])) {
            return true;
        }
    }
   	return false;
}

//*******************************************************************************************
// If ship contains the point a user enters (fires at ship), the ship has been hit
//*******************************************************************************************

void Ship::shotFiredAtPoint(const point& p) {
    if (containsPoint(p)) {
        hits.add(p);
    }
}

//*******************************************************************************************
// Returns true if point p is found in PointCollection hits
//*******************************************************************************************

bool Ship::isHitAtPoint(const point& p) {
    return (hits.contains(p)) ? true : false;
}

//*******************************************************************************************
// Returns the number of hits ship has endured
//*******************************************************************************************

int Ship::hitCount() const {
    return hits.getSize();
}

//*******************************************************************************************
// Operator =
//*******************************************************************************************

const Ship& Ship::operator=(const Ship& s) {
    length = s.length;
    orientation = s.orientation;
    origin = s.origin;
    
    points = s.points;
    hits = s.hits;
    return *this;
}


//*******************************************************************************************
//  Is Sunk
//*******************************************************************************************

bool Ship::isSunk() {
    return (hits.getSize() == length) ? true : false;
}
