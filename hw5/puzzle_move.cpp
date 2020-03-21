/* puzzle_move.cpp
 *
 * Melina Delgado
 *
 * cs427
 */

#include "puzzle_move.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>

namespace cs427_527
{
  PuzzleMove::PuzzleMove(int i)
  {
    moves.push_back((i));
  }
  
  PuzzleMove::PuzzleMove(int fromR, int fromC, int toR, int toC)
  {
    moves.push_back(fromR);
    moves.push_back(fromC);
    moves.push_back(toR);
    moves.push_back(toC);
  }

  std::string PuzzleMove::toString() const
  {
    if(moves.size() == 1)
    {
      return std::to_string(moves[0]);
    }
    else
    {
      return std::to_string(moves[0]) + " " + std::to_string(moves[1]) + " " + std::to_string(moves[2]) + " " + std::to_string(moves[3]);
    }
  }
  std::ostream& operator<<(std::ostream& os, const PuzzleMove& out)
  {
    return os << out.toString();
  }
}
