/*
 *  Ship.h
 *  Battleship
 */

#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include "Point.h"
#include "PointCollection.h"

/* In reality, a ship may be facing any direction,
 * east, north, north-north-east, etc. For the sake
 * of the this game (and for nastalgic purposes) we
 * stick with either east-west (Horizontal) facing
 * ships of north-south (Vertical) facing ship.
 */
enum direction { HORIZONTAL, VERTICAL };

class Ship
{
  private:
    int length;             /* Length of the ship. */
    direction orientation;
    point origin;           /* The "front" of the ship. */

    PointCollection points; /* All the points the ship contains.*/
    PointCollection hits;   /* Number of times ship has been hit by user. */

  public:
    /* constructors */
    Ship(point originPoint, direction orientationDirection, int lengthValue);
    Ship(const Ship& s);

    /* member functions */
    /** @brief Determines wheter the point p is contained in
     *         a ship on the board.
     *  @param p The point to be checked.
     *  @return bool True if there is a ship that contains
     *               point p, false otherwise
     */
    bool containsPoint(const point& p) const;

    /** @brief Determines whether two ships collide have a mutual point
     *  @param s Ship to be checked if collides.
     *  @return bool True if the two ships collide,
     *               false otherwise.
     */
    bool collidesWith(const Ship& s) const;

    /** @brief Register that a shot has been fired at point p.
     *  @param p The point that is being fired.
     *  @return
     */
    void shotFiredAtPoint(const point& p);

    /** @brief Determine wether point p has hit a ship.
     *  @param p the point in question.
     *  @return bool True if a ship is hit at given point,
     *               false otherwise.
     */
    bool isHitAtPoint(const point& p);

    /** @brief Get the number of hits ship has endured
     *  @return int The number of hits user has made.
     */
    int hitCount() const;

    /** @brief Equals operator (=) overload.
     *
     *  Easily and intuitively assign the Ship object.
     *
     *  @param s the ship to be copied.
     *  @return Ship the address of a new Ship, replicated from s.
     */
    const Ship& operator=(const Ship& s);

    /** @brief Determine wether a ship has been sunk.
     *
     *  A ship is sunk when all two, three, four or five points
     *  a ship contains has been hit. If not all the points a ship
     *  contains have been hit, then the ship has not been sunk.
     *
     *  @return bool True if all points contained by Ship have been
     *               hit, false othersise.
     */
    bool isSunk();

    /** @brief Get the length of a ship.
     *
     *  @return int An integer either 2, 3, 4 or 5. */
    int getLength() {return length;}
};

#endif
