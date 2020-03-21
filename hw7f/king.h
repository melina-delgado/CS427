#ifndef __KING_H__
#define __KING_H__

#include <string>

#include "stone.h"

namespace cs427_527
{
  class FissionBoard;
  
  class King : public Stone
  {
  public:
    /**
     * Creates a king owned by the given player at the given position.
     *
     * @param p 0 or 1
     * @param r a nonnegative integer
     * @param c a nonnegative integer
     */
    King(int p, int r, int c);

    /**
     * Destroys this king.
     */
    ~King();

    /**
     * Returns a printable representation of this stone.
     *
     * @return a printable representation of this stone
     */
    std::string toString() const override;

  protected:
    /**
     * Returns whether this stone can move backwards.
     *
     * @return true if and only if this stone can move backwards
     */
    bool canMoveBackwards() const override;

    /**
     * Determines if this stone is promoted if moving to the given
     * location.
     *
     * @param board the board this stone is on
     * @param toR a row on that board
     * @param toC a column on that board
     * @return true if this stone is promoted
     */
    bool checkPromote(const Board& board, int toR, int toC) const override;

  };
}
#endif
