/*
 * CS427 Assignment 6
 * 
 * Author: Melina Delgado
 *
 * spinout.cpp
 */

#include "spinout.h"
#include "puzzle.h"
#include "puzzle_move.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>

namespace cs427_527
{
  SpinOut::SpinOut() : Puzzle()
  {
    for(int i = 0; i <= 6; i++)
    {
      puzzle[i] = '/';
    }
    puzzle[SIZE] ='\0';
    finalstr = puzzle;
  }

  SpinOut::~SpinOut() {}

  SpinOut::SpinOut(const std::string &s)
  {
    for(int i = 0; i <= 6; i++)
    {
      puzzle[i] = s[i];
    }
    puzzle[SIZE] = '\0';
    finalstr = puzzle;
  }

  PuzzleMove* SpinOut::readMove(std::istream& moves)
  {
    int pos;
    if(moves >> pos)
    {
      PuzzleMove* moveObj = new cs427_527::PuzzleMove(pos);
      return moveObj;
    }
    return NULL;
  }

  bool SpinOut::isLegalMove(const PuzzleMove* moveObj) const
  {
    int i = moveObj->moves[0];
    if(i == 6)
    {
      return true;
    }
    int right_disk = i + 1;
    if(puzzle[right_disk] == '/')
    {
      if(right_disk == 6)
      {
        return true;
      }
      for(int j = right_disk+1; j<=6; j++)
      {
        if(puzzle[j] == '-')
        {
          return true;
        }
      }
    }
    return false;
  }

  void SpinOut::makeMove(PuzzleMove* moveObj)
  {
    int i = moveObj->moves[0];
    if(puzzle[i] == '-')
    {
      puzzle[i] = '/';
    }
    else
    {
      puzzle[i] = '-';
    }
    movecount++;
    finalstr = puzzle;
  }

  bool SpinOut::isSolved() const
  {
    for(int i = 0; i <= 6; i++)
    {
      if(puzzle[i] != '-')
      {
        return false;
      }
    }
    return true;
  }

  std::string SpinOut::toString() const
  {
    return finalstr; 
  }
}

