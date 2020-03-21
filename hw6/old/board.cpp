/**
 * Board.cpp
 *
 * Author: Melina Delgado
 * CS427 Homework 6
 *
 * Base class Board implementation for a grid-based board game
 */

#include <memory>
#include <iostream>

#include "board.h"

namespace cs427_527
{
  Board::Board()
  {
  }

  Board::~Board() 
  {
  }

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

  bool Board::inBounds(int r, int c) const
  {
    return r >= 0 && r < height && c >= 0 && c < width;
  }

  std::ostream& operator<<(std::ostream& os, const Board &board)
  {
    return os << board.toString();
  }
}

