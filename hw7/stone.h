#ifndef __CHECKER_H__
#define __CHECKER_H__

#include <string>
#include <memory>

namespace cs427_527
{
  class FissionBoard;

  /**
   * A checker.
   */
  class Stone: public Piece
  {
    public:
      /**
       * Creates a checker owned by the given player at the given position.
       *
       * @param p 0 or 1
       * @param r a nonnegative integer
       * @param c a nonnegative integer
       */
      Stone(int p, int r, int c);

      Stone();

      /**
       * Destroys this checker.
       */
      ~Stone();

      virtual bool isLegalMove(const Board& board, int toR, int toC) const;

      /**
       * Moves this checker to the given position on the given board,
       * provided the move is legal, considering the movement rules
       * for a checker.
       *
       * @param board a board
       * @param toR a row on that board
       * @param toC a column on that board
       */
      virtual void makeMove(Board& board, int toR, int toC);

      virtual std::string toString() const;
    protected:
      /**
       * Determines if it is legal to move this checker to the given
       * location on the board, considering only the contents of
       * that location.
       *
       * @param board the board this checker is on
       * @param toR a row on that board
       * @param toC a column on that board
       * @return true if and only if the move is legal, considering only
       * the contents of the destination
       */
      virtual bool isLegalDestination(const Board& board, int toR, int toC) const;

      /**
       * Determines if it is legal to move this checker the given
       * distance, considering only the distance.  The distance is
       * defined as the larger of the change in row and the change in
       * column.
       *
       * @param a nonnegative integer
       * @return true if it is generally legal to move this checker that distance
       */
      virtual bool isLegalDistance(const Board& board, int dist) const;

      virtual bool isOrthogonal(int toR, int toC) const;

      virtual bool isDiagonal(int toR, int toC) const;

      virtual bool isStopped(const Board& board, int toR, int toC) const;
  };
}

#endif
