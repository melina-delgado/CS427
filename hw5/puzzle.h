/* puzzle.h 
 *
 * Melina Delgado
 * CS427
 */
#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#include "puzzle_move.h"
#include <iostream>
#include <sstream>
#include <string>

namespace cs427_527
{
  class Puzzle
  {
    public:
      Puzzle();
      virtual ~Puzzle();
      /* returns an int representing the total number of moves completed thus far in the puzzle*/
      int totalMoves() const;

      /*virtual functions*/
      /* returns true or false depending on if puzzle is solved or not*/
      virtual bool isSolved() const=0;

      /* creates a PuzzleMove object depending on the number of ints in the stream */
      virtual PuzzleMove* readMove(std::istream&)=0;

      /* converts puzzle into a string */
      virtual std::string toString() const=0;

      /* determines whether move is legal */
      virtual bool isLegalMove(const PuzzleMove* move) const=0;

      /* changes puzzle board*/
      virtual void makeMove(PuzzleMove* move)=0;

      int movecount=0;
  };
  std::ostream& operator<<(std::ostream&, const Puzzle&);
}

#endif
