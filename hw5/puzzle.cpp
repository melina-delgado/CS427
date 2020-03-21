/* puzzle.cpp 
 *
 * Melina Delgado
 * cs427
 */

#include "puzzle.h"
#include "puzzle_move.h"
#include <iostream>
#include <sstream>
#include <string>

namespace cs427_527
{
  Puzzle::Puzzle() {}

  Puzzle::~Puzzle() {}

  int Puzzle::totalMoves() const 
  {
    return movecount;
  }

  std::ostream& operator<<(std::ostream& os, const Puzzle& out)
  {
    return os << out.toString();
  }
}
