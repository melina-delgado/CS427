#include "piece.h"

namespace cs427_527
{
  Piece::Piece() {}

  Piece::Piece(int p, int r, int c)
  : player(p), row(r), col(c) {}

  Piece::~Piece() {}

  int Piece::getPlayer() const
  {
    return player;
  }

  /*bool Piece::isLegalMove(const Board& board, int toR, int toC) const
  {
    return false;
  }

  void Piece::makeMove(Board& board, int toR, int toC)
  {
  }*/
}
