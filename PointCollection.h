/*
 *  PointCollection.h
 *  Battleship
 */

#ifndef POINT_COLLECTION_H
#define POINT_COLLECTION_H

#include "Point.h"

class PointCollection
{
private:
  int size;
  int capacity;
  point* data;

  void doubleArraySize();

public:
  /* default constructor */
  PointCollection();
  /* copy constructor */
  PointCollection(const PointCollection& c);
  /* destructor */
  ~PointCollection();

  /* member functions */
  /** @brief Add a point to the collection.
   *
   *  If there is not enough space in the collection array,
   *  the the size of the array is doubled.
   *
   *  @param p The point to add to the collection.
   *  @return void
   */
  void add(const point &p);

  /** @brief Looks up a point via index.
   *  @param index Any index from 0 to size-1.
   *  @return point& Address of the point located at
   *                 data[index]. */
  point& get(int index) const;

  /** @brief Get the size of the PointCollection.
   *  @return int The size of the PointCollection.
   */
  int getSize() const;

  /** @brief Determin wether p is contained in the PointCollection.
   *  @param p The point in question.
   *  @return bool True if p is in the PointCollection, false otherwise.
   */
  bool contains(const point &p) const;

  /** @brief Inserts a point into the PointCollection.
   *  @param p The point to be added.
   *  @return PointCollection& The new point collection containing p.
   */
  PointCollection& operator<<(const point &p);

  /** @brief Allow the PointCollection to be indexed like an array.
   *  @param index Offset from &PointCollection.
   *  @return point& the address of the index'th point in the collection.
   */
  point& operator[](int index) const;

  /** @brief Sets the state of the receiving instance so that it
   *         matches the argument.
   *  @param c The right-hand-side of the the equal symbol.
   *  @return PointCollection& The address of the PointCollection, as a copy.
   */
  const PointCollection& operator=(const PointCollection &c);
};

#endif
