/*
 * CS427 Assignment 2
 *
 * Author: Melina Delgado
 * Date: 10/11 11:59pm
 *
 * mainConway.cpp
 *
 */

#include "conway.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::cin;
using std::istringstream;
using std::cerr;

int main(int argc, char **argv)
{
  bool interactive = false;
  bool file = false;
  bool fileGiven = false;
  bool noninteractive = false;
  string filename;
  string interact = "-i";
  string fileFlag = "-f";
  int index = 0;

  if(argc>1)
  {
    for(int i = 1; i < argc; i++)
    {
      if(!file && !noninteractive && argv[i] == interact)
      {
        interactive = true;
      }
      else if(argv[i] == fileFlag)
      {
        file = true;
      }
      else if(file)
      {
        filename = argv[i];
        fileGiven = true;
        file = false;
      }
      else if(!file && !interactive)
      {
        noninteractive = true;
        index = i;
        break;
      }
      else
      {
        std::cerr << "Invalid argument" << std::endl;
        exit(1);
      }
    }
  }
  cs427_527::Conway puzzle;

  if(fileGiven)
  {
    ifstream File (filename);
    if(File.is_open() && File.peek() != std::ifstream::traits_type::eof())
    {
      puzzle = cs427_527::Conway(File);
    }
    else
    {
      std::cerr << "Invalid file given or file is empty" << std::endl;
      exit(1);
    }
  }

  if(interactive)
  {
    cout << puzzle;
    string line;
    while(getline(cin, line))
    {
      int row1 = 0;
      int col1 = 0;
      int row2 = 0;
      int col2 = 0;

      if(line.empty())
        continue;

      istringstream ss(line);

      ss >> row1 >> col1 >> row2 >> col2;

      if(puzzle.isLegalMove(row1, col1, row2, col2))
      {
        puzzle.makeMove(row1, col1, row2, col2);
        cout << puzzle;
      }
      else
      {
        cout << "illegal move" << endl;
      }

      if(puzzle.isSolved())
      {
        cout << puzzle.moves << " moves" << endl;
        break;
      }
    }
  }
  else
  {
    long int row1 = 0;
    long int col1 = 0;
    long int row2 = 0;
    long int col2 = 0;
    int count = 0;
    int position = 1;
    bool solved = false;

    for(int i = index; i < argc; i++)
    {
      if(count == 0)
      {
        row1 = strtol(argv[i], NULL, 10);
        count++;
      }
      else if(count == 1)
      {
        col1 = strtol(argv[i], NULL, 10);
        count++;
      }
      else if(count == 2)
      {
        row2 = strtol(argv[i], NULL, 10);
        count++;
      }
      else if(count == 3)
      {
        col2 = strtol(argv[i], NULL, 10);
        if(puzzle.isLegalMove(row1, col1, row2, col2))
        {
          puzzle.makeMove(row1, col1, row2, col2);
        }
        else
        {
          cout << "Conway: illegal move "<< row1 << " " << col1 << " " << row2 << " " << col2 << " in position " << position << " for" << endl;
          cout << puzzle;
          solved = true;
          break;
        }

        if(puzzle.isSolved())
        {
          cout << "SOLVED" << endl;
          solved = true;
          break;
        }
        count = 0;
        position++;
      }
    }
    if(!solved)
    {
      cout << puzzle;
    }
  }
}
