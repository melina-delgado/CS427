/*
 * CS427 Assignment 3
 *
 * Author: Melina Delgado
 * Date: 9/27 11:59pm
 *
 * conway.cpp
 */

#include "conway.h"
#include <string>
#include <iostream>
#include <sstream>

using std::ostream;
using std::istream;
using std::string;
using std::ostringstream;
using std::endl;
using std::getline;
using std::istringstream;
using std::cout;

namespace cs427_527
{
  //default constructor
  Conway::Conway()
  {
    rowLen = 5;
    columnLen = 6;

    //allocate rows
    puzzle = new char *[rowLen];

    //allocate columns
    for(int i = 0; i < rowLen; i++)
    {
      puzzle[i] = new char[columnLen];
    }

    //initialize
    for(int i = 0; i < rowLen; i++)
    {
      for(int j = 0; j < columnLen; j++)
      {
        puzzle[i][j] = '.';
      }
    }

    for(int i = 1; i < 4; i++)
    {
      puzzle[2][i] = 'X';
    }
    puzzle[3][3] = 'X';
  }

  //constructor with parameters
  Conway::Conway(istream& in)
  {  
    string dimensions;
    getline(in, dimensions);

    if(dimensions.empty())
    {
      rowLen = 5;
      columnLen = 6;
    }
    else
    {
      istringstream d(dimensions);
      if(d >> rowLen)
      {
        if(d >> columnLen)
        {
          if(rowLen <= 0)
          {
            rowLen = 5;
          }
          if(columnLen <= 0)
          {
            columnLen = 6;
          }
        }
      }

      puzzle = new char*[rowLen];

      for(int i = 0; i < rowLen; i++)
      {
        puzzle[i] = new char[columnLen];
      }

      string row;
      for(int i = 0; i < rowLen; i++)
      {
        getline(in, row);
        for(int j = 0; j < columnLen; j++)
        {
          puzzle[i][j] = row[j];
        }
      }
    }
  }

  //destructor
  Conway::~Conway()
  {
    for(int i = 0; i < rowLen; i++)
    {
      delete [] puzzle[i];
    }

    delete []puzzle;
    puzzle = NULL;
  }

  //copy constructor
  Conway::Conway(const Conway& c)
  {
    //copy primitive values
    moves = c.moves;
    rowLen = c.rowLen;
    columnLen = c.columnLen;

    //deep copy
    puzzle = new char*[rowLen];
    for(int i = 0; i < rowLen; i++)
    {
      puzzle[i] = new char[columnLen];
    }

    for(int i = 0; i < rowLen; i++)
    {
      for(int j = 0; j < columnLen; j++)
      {
        puzzle[i][j] = c.puzzle[i][j];
      }
    }
  }

  Conway& Conway::operator=(const Conway& c)
  {
    //check for self assignment
    if(&c != this)
    {
      for(int i = 0; i < rowLen; i++)
      {
        delete [] puzzle[i];
      }

      delete []puzzle;
      puzzle = NULL;

      //copy primitive
      moves = c.moves;
      rowLen = c.rowLen;
      columnLen = c.columnLen;

      //deep copy
      puzzle = new char*[rowLen];
      for(int i = 0; i < rowLen; i++)
      {
        puzzle[i] = new char[columnLen];
      }

      for(int i = 0; i < rowLen; i++)
      {
        for(int j = 0; j < columnLen; j++)
        {
          puzzle[i][j] = c.puzzle[i][j];
        }
      }
    }

    return *this;
  }

  bool Conway::isLegalMove(int fromR, int fromC, int toR, int toC) const
  {
    int intermed = 0;
    //horizontal move
    if(fromR==toR)
    {
      if(abs(fromC-toC) != 2)
      {
        return false;
      }

      intermed = (fromC + toC)/2;

      if(puzzle[fromR][intermed] == 'X')
      {
        if(puzzle[fromR][toC] == '.')
        {
          return true;
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    //vertical move
    else if(fromC == toC)
    {
      if(abs(fromR-toR) != 2)
      {
        return false;
      }

      intermed = (fromR + toR)/2;

      if(puzzle[intermed][fromC] == 'X')
      {
        if(puzzle[toR][toC] == '.')
        {
          return true;
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  void Conway::makeMove(int fromR, int fromC, int toR, int toC)
  {
    int intermed = 0;
    if(fromR==toR)
    {
      intermed = (fromC + toC)/2;

      puzzle[fromR][fromC] = '.';
      puzzle[fromR][intermed] = '.';
      puzzle[toR][toC] = 'X';
    }
    else if(fromC==toC)
    {
      intermed = (fromR + toR)/2;

      puzzle[fromR][fromC] = '.';
      puzzle[intermed][fromC] = '.';
      puzzle[toR][toC] = 'X';
    }

    moves++;
  }

  int Conway::totalMoves() const
  {
    return moves; 
  }

  bool Conway::isSolved() const
  {
    for(int i = 0; i < columnLen; i++)
    {
      if(puzzle[0][i] == 'X')
      {
        return true;
      }
    }
    return false;
  }

  string Conway::toString() const
  {
    ostringstream out;

    for(int i = 0; i < rowLen; i++)
    {
      for(int j = 0; j < columnLen; j++)
      {
        out << puzzle[i][j];
      }
      out << endl;
    }

    return out.str();
  }

  ostream& operator<<(ostream& os, const Conway& out)
  {
    return os << out.toString();
  }
}
