#include "piece.h"
#include "board.h"

#include <vector>
#include <string>

namespace cs427_527
{
  Board::Board() {}

  Board::Board(int w, int h, int t) 
    : width(w),
    height(h),
    turn(t),
    board(h, std::vector<std::shared_ptr<Piece>>(w, nullptr))
  {
  }

  Board::~Board() {}

  std::shared_ptr<Piece> Board::getPiece(int r, int c)
  {
    if (inBounds(r, c))
    {
      return board[r][c];
    }
    else
    {
      return nullptr;
    }
  }

  std::shared_ptr<const Piece> Board::getPiece(int r, int c) const
  {
    if (inBounds(r, c))
    {
      return board[r][c];
    }
    else
    {
      return nullptr;
    }
  }

  void Board::removePiece(int r, int c)
  {
    if (inBounds(r, c))
    {
      board[r][c] = nullptr;
    }
  }

  void Board::placePiece(int r, int c, std::shared_ptr<Piece> p)
  {
    if (inBounds(r, c))
    {
      board[r][c] = p;
    }
  }

  bool Board::inBounds(int r, int c) const
  {
    return r >= 0 && r < height && c >= 0 && c < width;
  }

  int Board::getWidth() const
  {
    return width;
  }

  int Board::getHeight() const
  {
    return height;
  }

  int Board::getCurrentPlayer() const
  {
    return turn;
  }

  std::ostream& operator<<(std::ostream& os, const Board &board)
  {
    return os << board.toString();
  }
}
