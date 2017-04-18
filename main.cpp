
/** @file main.c
 *  @brief This is the Battleship Main function.
 *  @author Richard Khillah
 *  @bugs No known bugs.
 */
#include "PointCollection.h"
#include "Ship.h"
#include "Board.h"
#include <iostream>

using namespace std;
int main(){
  /* Time seed for random number generator. */
  srand(time(0));

  Board b;      /* The board on which the user will play. */
  b.display();  /* Display the fresh board. */

  int x, y;

  do{
    /* Get the user guess. */
    cout << "\nEnter a coordinates: ";
    cin >> x;
    cin.ignore();
    cin >> y;

    /* Determine wether the user hit or missed a ship. */
    if (b.fireShot(x, y))
      cout << "Hit!!\n";
    else
      cout << "Miss...\n";

    /* Display the board updated with latest user input. */
    b.display();

  /* Continue to ask user to input coordinates until all
   * the ships have been sunk.
   */
  }while (b.unsunkShipCount() != 0);

  return 0;
}
