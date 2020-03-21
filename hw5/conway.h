/*
 * CS 427 Assignment 3
 *
 * Author: Melina Delgado
 * Date: 10/11 11:59pm
 *
 * conway.h
 */

#ifndef __CONWAY_H__
#define __CONWAY_H__

#include "puzzle.h"
#include "puzzle_move.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using std::ostream;
using std::istream;
using std::string;

namespace cs427_527
{
  class Conway: public Puzzle
  {
    public:
      /* Conway() 
       * Constructor that creates the initial state of a 4-piece puzzle with a 5-row, 6-column board with 3 pieces in columns 1 through 3 of the middle row and another piece below the rightmost piece */
      Conway();

      /* Conway(istream&) 
       * Creates a puzzle whose initial state is read from the given stream.
       * The stream will contain two integers separated by whitespace and possibly with leading and trailing whitespace on the first line for the width and the height of the board (in that order).
       * Following the first line, there will be one line per row containing a string of 'X' and '.' characters. 'X's indicate initial positions of pieces. Each such string will be as long as the board is wide */
      Conway(istream&);

      /*destructor for conway*/
      ~Conway();

      PuzzleMove* readMove(std::istream&);

      /* Conway(const Conway&) 
       * A copy constructor that creates an independent copy of the given puzzle state (changes to the new copy shouldn't affect the original) */
      Conway(const Conway&);

      /* Conway& operator = (const Conway&) 
       * An assignment operator that makes the puzzle on the left of the assignment operator an independent copy of the puzzle on the right and returns a reference to the puzzle on the left */
      Conway& operator = (const Conway&);

      /* bool isLegalMove(int fromR, int fromC, int toR, int toC) const 
       * Takes integers representing the row and column of the position on the board to move from and to move to and determines whether such a move is legal according to the rules of the puzzle. If either of the positions is not on the board then the move is illegal.*/
      bool isLegalMove(const PuzzleMove* moveObj) const;

      /* void makeMove(int fromR, int fromC, int toR, int toC)
       * Takes a legal move represented by integers by giving the row and column of the position on the board to move from and to move to and modifies the current object to reflect the result of that move. */
      void makeMove(PuzzleMove* moveObj);

      /* int totalMoves() const
       * Counts the number of legal moves performed since the initial state of the original object (so the count is copied when objects are copied, moved, or assigned)*/
      int totalMoves() const;

      /* bool isSolved() const
       * Determines if the current object is in its solved configuration (some piece in the top row)*/
      bool isSolved() const;

      /* Converts board to string to be printed*/
      string toString() const;

    private:
      const int intermediate(int, int);
      char **puzzle;
      int rowLen;
      int columnLen;
  };
}

#endif
