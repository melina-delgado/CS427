/*
 * CS427 Assignment 2
 *
 * Author: Melina Delgado
 * Date: 9/27 11:59pm
 *
 * spinout.h
 */

#ifndef __SPINOUT_H__
#define __SPINOUT_H__

#include "puzzle.h"
#include "puzzle_move.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>

namespace cs427_527
{
  class SpinOut: public Puzzle
  {
    public:
      /*Initializes the puzzle so all disks are vertical*/
      SpinOut();

      ~SpinOut();

      PuzzleMove* readMove(std::istream&);

      /*Initializes puzzle according to given string*/
      SpinOut(const std::string &s);

      /*Takes integer between 0 and 6 inclusive and determines whether it's possible to rotate that disk in the current object to it's other orientation*/
      bool isLegalMove(const PuzzleMove* moveObj) const;

      /*rotates indicated disk in the current object into its other orientation, provided, that such a move is legal*/
      void makeMove(PuzzleMove *moveObj);

      /*Counts the total number of legal moves performed on the current object since it was created*/
      int totalMoves() const;

      /*Determines if the current object is in its solved configuration*/
      bool isSolved() const;

      /*Returns a string rep. of the current object in the same format as that passed to the second version of the constructor*/
      std::string toString() const;
    
      /*static size of configuration*/
      static const int SIZE = 7;
    
    private:
      char puzzle[SIZE+1];
      std::string finalstr;
  };
}

#endif
