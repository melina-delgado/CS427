#include <memory>

#include "piece.h"
#include "stone.h"
#include "board.h"
#include "fissionboard.h"
#include "light.h"

#include "math.h"

namespace cs427_527
{
  Stone::Stone(int p, int r, int c)
    : Piece(p, r, c)
  {
  }

  Stone::~Stone()
  {
  }

  Stone::Stone() {}
  bool Stone::isLegalMove(const Board& board, int toR, int toC) const
  {
    int dist = distance(row, col, toR, toC);
    return (board.inBounds(row, col) && board.inBounds(toR, toC)
        && isLegalDistance(board, dist)
        && isStopped(board, toR, toC)
        && (isDiagonal(toR, toC) || isOrthogonal(toR, toC))
        && isLegalDestination(board, toR, toC));
  }

  bool Stone::isStopped(const Board& board, int toR, int toC) const
  {
    FissionBoard f;
    int afterR = f.getNextR(toR, row);
    int afterC = f.getNextC(toC, col);
    return !board.inBounds(afterR, afterC) || board.getPiece(afterR,afterC) != nullptr;
  }

  bool Stone::isLegalDestination(const Board& board, int toR, int toC) const
  { 
    // destination must be empty
    return board.getPiece(toR, toC) == nullptr;
  }

  bool Stone::isDiagonal(int toR, int toC) const
  {
    int diffDest = toR-toC;
    int diffOrig = row-col;
    int sumDest = toR+toC;
    int sumOrig = row+col;
    return diffDest == diffOrig || sumDest == sumOrig;
  }

  bool Stone::isOrthogonal(int toR, int toC) const
  {
    return toR==row || toC == col;
  }

  void Stone::makeMove(Board& board, int toR, int toC)
  {
    if (isLegalMove(board, toR, toC))
    {
      // get a shared pointer to this piece (consider what happens
      // after remove without this)
      std::shared_ptr<Piece> p = board.getPiece(row,col);
      std::shared_ptr<Stone> self = std::dynamic_pointer_cast<Stone>(p);

      // remove this piece from original location
      board.removePiece(row, col);

      //update location of this piece
      row = toR;
      col = toC;

      board.placePiece(toR, toC, self);
    }
  }

  bool Stone::isLegalDistance(const Board& board, int d) const
  {
    const int width = board.getWidth();
    const int height = board.getHeight();
    return d > 0 && (d <= width || d <= height);
  }

  std::string Stone::toString() const
  {
    return (player == 0 ? "RR" : "BB");
  }
}
