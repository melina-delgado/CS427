#include <algorithm>
#include <cctype>

#include "piece.h"
#include "king.h"
#include "stone.h"

namespace cs427_527
{
  King::King(int p, int r, int c)
    : Stone(p, r, c)
  {
  }

  King::~King()
  {
  }

  bool King::canMoveBackwards() const
  {
    // kings can move backwards
    return true;
  }

  bool King::checkPromote(const Board& board, int toR, int toC) const
  {
    // kings are never promoted
    return false;
  }

  std::string King::toString() const
  {
    // convert base class's result to upper case
    std::string result = Stone::toString();
    std::transform(result.begin(), result.end(), result.begin(), toupper);
    return result;
  }
}

