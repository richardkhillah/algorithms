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
    Ship *ships[4];           /* To keep track of created ships. */
    PointCollection misses;   /* Incorrect user guessed shots. */

    /* Private utility function. */
    /** @brief Generate a ship object with the given length, and
     *         a random origin and orientation.
     *  @param l Desired length of the ship to be created.
     *  @return Ship* The newly created ship of length l.
     */
    Ship* generateShipWithLength(int l);

  public:
    /** @brief Default contructor. Set up the board.
     *
     * A constructor which creates four randomly placed and
     * oriented ships and stores pointers to them into the
     * ships array. The ships have the following lengths:
     * 5, 4, 3, 2
     */
    Board();

    /** @brief Fire the shot the user enters on the command line.
     *
     * Updates state to account for a shot at (x, y), i.e.
     * if there is a ship at (x, y) the ship now knows it //ishitat(x,y).
     * If there is no ship at(x,y) then the board has recorded
     * this in its misses PointCollection
     *
     *  @param x User guessed x-coordinate of ship.
     *  @param y User guessed y-coordinate of ship.
     *  @return bool True if some ship in ships contains (x, y),
     *               false otherwise.
     */
    bool fireShot(int x, int y);

    /** @brief The number of ships that have not been sunk from user guesses.
     *  @return int Integer between 0 and 4.
     */
    int unsunkShipCount();

    /** @brief Write the the board to stdout.
     *
     *  The grid display shows hits, misses and empty squares
     *  @return void.
     */
    void display();
};

#endif
