#ifndef __CHECKERBOARD_H__
#define __CHECKERBOARD_H__

#include <string>
#include <iostream>
#include <vector>
#include <memory>

namespace cs427_527
{
  class Checker;

  /** 
   * A checkerboard.
   */
  class CheckerBoard: public Board
  {
    public:
      enum Color { BLACK, RED };

      /**
       * Creates a checkerboard with pieces in their initial locations.
       */
      CheckerBoard();

      /**
       * Destoys this board.
       */
      virtual ~CheckerBoard();

      /**
       * Returns the color of this board at the given position.
       *
       * @param row a row on this board
       * @param col a column on this board
       * @return the color of that position.
       */
      Color getBoardColor(int row, int col) const;

      bool isLegalMove(int fromR, int fromC, int toR, int toC) const;

      void makeMove(int fromR, int fromC, int toR, int toC);

      bool gameOver() const;

      std::string toString() const;

      //bool inBounds(int r, int c) const;
    protected:
      /**
       * Returns the distance of the longest legal move on this board.
       *
       * @return the distance of the longest legal move
       */
      int findLongestMove() const;

      /**
       * Returns the distance of the longest legal move by the piece
       * at the given position on this board.
       *
       * @param fromR the row of a piece on this board
       * @param fromC the column of a piece on this board
       * @return the distance of the longest legal move for the piece
       * at that position
       */
      int findLongestMove(int fromR, int fromC) const;

      /**
       * A pointer to the piece that is in the middle of a sequence
       * of jumps.  This piece is the only one it is legal to move.
       * If there is no such piece, this is nullptr and it is legal
       * to move any piece that has a legal move.
       */
      std::shared_ptr<Piece> jumping;
  };
}

#endif

