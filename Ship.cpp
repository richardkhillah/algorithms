/** @file Ship.cpp
 *  @brief Implementation of Ship.h.
 *
 *  Refer to Ship.h for function details.
 *
 *  @author Richard Khillah
 *  @bugs No known bugs
 */

#include "Ship.h"
#include <iostream>
using namespace std;

/*
 * Constructor: creates ship of length l, starting at originPoint with o orientation
 */
Ship::Ship(point originPoint, direction d, int l) :
  origin(originPoint), length(l), orientation(d) {

  if (d == HORIZONTAL) {
    for (int i = 0; i < l; i++)
      points.add(point(originPoint.getX() + i, originPoint.getY()));
  } else {
    for (int i = 0; i < l; i++)
      points.add(point(originPoint.getX(), originPoint.getY() + i));
  }
}

/*
 * Copy constructor
 */
Ship::Ship(const Ship& s) {
  *this = s;
}

bool Ship::containsPoint(const point& p) const{
  return (points.contains(p) ? true : false);
}

bool Ship::collidesWith(const Ship& s) const {
  for (int i = 0; i < s.points.getSize(); i++)
    if (containsPoint(s.points[i]))
      return true;
 	return false;
}

void Ship::shotFiredAtPoint(const point& p) {
  if (containsPoint(p))
    hits.add(p);
}

bool Ship::isHitAtPoint(const point& p) {
  return (hits.contains(p)) ? true : false;
}

int Ship::hitCount() const {
  return hits.getSize();
}

const Ship& Ship::operator=(const Ship& s) {
  /* Copy all information */
  length = s.length;
  orientation = s.orientation;
  origin = s.origin;
  points = s.points;
  hits = s.hits;

  /* return this object. */
  return *this;
}

bool Ship::isSunk() {
  return (hits.getSize() == length) ? true : false;
}
