#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "board.h"
#include "fissionboard.h"

using cs427_527::FissionBoard;

int main(int argc, char **argv)
{
  if(argc != 3)
  {
    fprintf(stderr, "Invalid number of args\n");
    exit(1);
  }
  int width;
  int height;
  std::istringstream w (argv[1]);
  std::istringstream h (argv[2]);
  FissionBoard b;
  if(w >> width)
  {
    if(h >> height)
    {
      FissionBoard b(width, height);
    }
    else
    {
      fprintf(stderr, "Height must be an int\n");
      exit(1);
    }
  }
  else
  {
    fprintf(stderr, "Width must be an int\n");
    exit(1);
  }

  std::cout << b;
  while (!b.gameOver() && std::cin)
  {
    std::cout << "PLAYER " << b.getCurrentPlayer() << std::endl;
    std::string move;
    if (std::getline(std::cin, move))
    {
      std::istringstream in(move);
      int fromR, fromC, toR, toC;
      if (in >> fromR >> fromC >> toR >> toC)
      {
        if (b.isLegalMove(fromR, fromC, toR, toC))
        {
          b.makeMove(fromR, fromC, toR, toC);
          std::cout << b;
        }
        else
        {
          std::cout << "illegal move" << std::endl;
        }
      }
      else
      {
        std::cout << "invalid input" << std::endl;
      }
    }
  }
  if (b.gameOver())
  {
    std::cout << (b.getCurrentPlayer() + 1) % 2 << " wins" << std::endl;
  }
}

