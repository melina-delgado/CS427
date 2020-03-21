#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <fstream>

#include "board.h"
#include "fissionboard.h"

using cs427_527::FissionBoard;

int main(int argc, char **argv)
{
  if(argc != 3)
  {
    fprintf(stderr, "Invalid number of arguments.\n");
    exit(1);
  }
  std::istringstream width (argv[1]);
  std::istringstream height (argv[2]);
  int w, h;
  if(width >> w && height >> h)
  {
    if(w < 4 || h < 4)
    {
      fprintf(stderr, "Height and width must be at least 4\n");
      exit(1);
    }
    if(w < h)
    {
      fprintf(stderr,"Width must be as large as height\n");
      exit(1);
    }
    if(w%2 != 0 || h%2 != 0)
    {
      fprintf(stderr, "Width and height must be even\n");
      exit(1);
    }
  }
  else
  {
    fprintf(stderr, "Invalid height or width given\n");
  }

  FissionBoard b(w,h);
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
          std::ofstream html ("fission_output.html", std::ofstream::out);
          if(html)
          {
            b.htmlPrint(html);
            html.close();
          }
          else
            std::cerr << "Error opening file fission_output.html" << std::endl;
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
    if(b.isDraw())
      std::cout << "Draw" << std::endl;
    else
      std::cout << (b.getCurrentPlayer() + 1) % 2 << " wins" << std::endl;
  }
}

