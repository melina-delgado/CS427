/*
 * CS427 Assignment 2
 * 
 * Author: Melina Delgado
 * Date: 9/27 11:59pm
 *
 * spinout.cpp
 */

#include "spinout.h"
#include <string>
#include <iostream>
#include <stdbool.h>

namespace cs427_527
{

  SpinOut::SpinOut()
  {
    for(int i = 0; i <= 6; i++)
    {
      puzzle[i] = '/';
    }
    puzzle[SIZE] ='\0';
    finalstr = puzzle;
  }

  SpinOut::SpinOut(const std::string &s)
  {
    for(int i = 0; i <= 6; i++)
    {
      puzzle[i] = s[i];
    }
    puzzle[SIZE] = '\0';
    finalstr = puzzle;
  }

  bool SpinOut::isLegalMove(int i)
  {
    if(i < 0 || i > 6)
    {
      return false;
    }
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
        if(puzzle[j] != '-')
        {
          return false;
        }
      }
      return true;
    }
    return false;
  }

  void SpinOut::makeMove(int i)
  {
    if(isLegalMove(i))
    {
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
  }

  int SpinOut::totalMoves() const
  {
    return movecount;
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

