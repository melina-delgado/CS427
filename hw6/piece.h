#ifndef __PIECE_H__
#define __PIECE_H__

#include <string>

namespace cs427_527
{
  class Board;

  /**
   * A piece.
   */
  class Piece
  {
    public:
      Piece();

      Piece(int p, int r, int c);

      virtual ~Piece();

      /**
       * Returns the index of the player this checker belongs to.
       *
       * @return the index of the owner
       */
      int getPlayer() const;

      /**
       * Returns a printable representation of this checker.
       *
       * @return a printable representation of this checker
       */
      virtual std::string toString() const=0;

      virtual bool isLegalMove(const Board& board, int toR, int toC) const=0;

      virtual void makeMove(Board& board, int toR, int toC)=0;
    protected:
      /**
       * The index of the player this checker belongs to.
       */
      int player;

      /**
       * The row of the position of this checker.
       */
      int row;

      /**
       * The column of the position of this checker.
       */
      int col;
  };
}
#endif
