#ifndef __FISSIONBOARD_H__
#define __FISSIONBOARD_H__

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

namespace cs427_527
{
  class Stone;

  /** 
   * A fissionboard.
   */
  class FissionBoard: public Board
  {
    public:
      enum Color { GRAY, WHITE };

      /**
       * Creates a fissionboard with pieces in their initial locations.
       */
      FissionBoard(int w, int h);

      FissionBoard();

      /**
       * Destoys this board.
       */
      virtual ~FissionBoard();

      /* Changes turn */
      int changeTurn(int turn);

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

      virtual int getNextR(const int toR, const int row) const;

      virtual int getNextC(const int toC, const int col) const;

      virtual void htmlPrint(std::ofstream& os);

      virtual bool isDraw() const;
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

      virtual void removeStones(int row, int col);

      virtual bool isEmpty() const;

      virtual int stoneCount(int p) const;
  };
}

#endif

