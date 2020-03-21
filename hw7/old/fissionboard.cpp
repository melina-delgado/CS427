#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>

#include "board.h"
#include "fissionboard.h"
#include "piece.h"
#include "stone.h"
#include "light.h"

#include "math.h"

namespace cs427_527
{
  FissionBoard::FissionBoard() {}

  FissionBoard::FissionBoard(int w, int h)
    : Board(w, h, 0)
  {
    bool light = false;
    if(h >= 6)
    {
      light=true;
    }

    int end, start;
    turn = 0;
    start = 0;
    end = 1;
    for(int r = height/2 -1; r >= 1; r--)         //quadrant 1
    {
      for(int c = width/2 -1; c >= end; c--)
      {
        if(light && c ==2)
        {
          board[r][c] = std::make_shared<Light>(turn, r, c);
        }
        else
        {
          board[r][c] = std::make_shared<Stone>(turn, r, c);
        }
        turn = changeTurn(turn);
      }
      start = changeTurn(start);
      turn = start;
      end++;
    }

    start = 1;
    turn = 1;
    end = width - 2;
    for(int r = height/2 -1; r >= 1; r--)           //quadrant 2
    {
      for(int c = width/2; c <= end; c++)
      {
        if(light && c == width-3)
        {
          board[r][c] = std::make_shared<Light>(turn, r, c);
        }
        else
        {
          board[r][c] = std::make_shared<Stone>(turn, r, c);
        }
        turn = changeTurn(turn);
      }
      start = changeTurn(start);
      turn = start;
      end--;
    }

    turn = 1;
    end = 1;
    start = 1;
    for(int r = height/2; r < height-1; r++)        //quadrant 3
    {
      for(int c = width/2 -1; c >= end; c--)
      {
        if(light && c==2)
        {
          board[r][c] = std::make_shared<Light>(turn, r, c);
        }
        else
        {
          board[r][c] = std::make_shared<Stone>(turn, r, c);
        }
        turn = changeTurn(turn);
      }
      start = changeTurn(start);
      turn = start;
      end++;
    }
    end = width-1; 
    turn = 0;
    start = 0;
    for(int r = height/2; r < height -1; r++)     //quadrant 4
    {
      for(int c = width/2; c < end; c++)
      {
        if(light && c == width-3)
        {
          board[r][c] = std::make_shared<Light>(turn, r, c);
        }
        else
        {
          board[r][c] = std::make_shared<Stone>(turn, r, c);
        }
        turn = changeTurn(turn);
      }
      start = changeTurn(start);
      turn = start;
      end--;
    }
    turn = 0;
  }

  FissionBoard::~FissionBoard()
  {
  }

  bool FissionBoard::isEmpty() const
  {
    for(int r = 0; r < height; r++)
    {
      for(int c = 0; c< width; c++)
      {
        if(getPiece(r,c) != nullptr)
          return false;
      }
    }
    return true;
  }

  bool FissionBoard::isDraw() const
  {
    return isEmpty() || (stoneCount(0) == 1 && stoneCount(1) == 1); 
  }

  int FissionBoard::stoneCount(int p) const
  {
    int count = 0;
    for(int r = 0; r<height; r++)
    {
      for(int c = 0; c<width; c++)
      {
        if(getPiece(r,c) != nullptr && getPiece(r,c)->getPlayer() == p)
        {
          count++;
        }
      }
    }
    return count;
  }

  void FissionBoard::htmlPrint(std::ofstream& os)
  {
    os << "<!DOCTYPE html>" << std::endl << "<html>" << std::endl <<
      "<head>" << std::endl << "<meta charset=\"UTF-8\">" << std::endl <<
      "<title>Fission</title>" << std::endl << "</head>" << std::endl <<
      "<body>" << std::endl << "<canvas id=\"board\" width=\""<< 20*width << "\" height=\""<< 20*height << "\"></canvas>" 
      << std::endl << "<script>" << std::endl << "var canvas = document.getElementById(\'board\');" 
      << std::endl << "var g = canvas.getContext(\'2d\');" << std::endl;
    for(int r = 0; r < height; r++)
    {
      for(int c = 0; c < width; c++)
      {
        if (getBoardColor(r, c) == Color::GRAY)
        {
          os << "g.fillStyle = \'#808080\';\n";
        }
        else
        {
          os << "g.fillStyle = \'#FFFFFF\';\n";
        }
        os << "g.fillRect(" << 20*c << ", " << 20*r << ", 20, 20);"
          << std::endl;
      }
    }
    for (int r = 0; r < height; r++)
    {
      for (int c = 0; c < width; c++)
      {
        if (getPiece(r, c) != nullptr)
        {
          os << "g.beginPath();" << std::endl << "g.arc(" << 20*c +10
            << ", " << 20*r +10;
          if(getPiece(r,c)->toString() == "RR")
          {
            os << ", 8, 0, 2*Math.PI);" << std::endl
              << "g.fillStyle = \'#FF0000\';" << std::endl;
          }
          else if(getPiece(r,c)->toString() == "rr")
          {
            os << ", 5, 0, 2*Math.PI);" << std::endl
              << "g.fillStyle = \'#FF0000\';" << std::endl;
          }
          else if(getPiece(r,c)->toString() == "BB")
          {
            os << ", 8, 0, 2*Math.PI);" << std::endl
              << "g.fillStyle = \'#0000FF\';" << std::endl;
          }
          else
          {
            os << ", 5, 0, 2*Math.PI);" << std::endl
              << "g.fillStyle = \'#0000FF\';" << std::endl;
          }
          os << "g.fill();" << std::endl;
        }
      }
    }
    os << "</script>" << std::endl << "</body>" << std::endl
      << "</html>" << std::endl;
  }

  FissionBoard::Color FissionBoard::getBoardColor(int r, int c) const
  {
    if (r % 2 == c % 2)
    {
      return Color::WHITE;
    }
    else
    {
      return Color::GRAY;
    }
  }

  int FissionBoard::changeTurn(int turn)
  {
    if(turn == 0) { return 1; }
    return 0;
  }

  bool FissionBoard::isLegalMove(int fromR, int fromC, int toR, int toC) const
  {
    if (!inBounds(fromR, fromC) || !inBounds(toR, toC))
    {
      return false;
    }

    // move is legal if is moves current player's stone legally
    std::shared_ptr<const Piece> moving = getPiece(fromR, fromC);
    return (moving != nullptr
        && moving->getPlayer() == turn
        && moving->isLegalMove(*this, toR, toC));
  }

  int FissionBoard::findLongestMove() const
  {
    int longest = 0;
    for (int fromR = 0; fromR < height; fromR++)
    {
      for (int fromC = 0; fromC < width; fromC++)
      {
        if (getPiece(fromR, fromC) != nullptr
            && getPiece(fromR, fromC)->getPlayer() == turn)
        {
          longest = imax(longest, findLongestMove(fromR, fromC));
        }
      }
    }
    return longest;
  }

  int FissionBoard::getNextR(const int toR, const int row) const 
  {
    if(toR < row)
      return toR-1;
    else if(toR == row)
      return toR;
    return toR+1;
  }

  int FissionBoard::getNextC(const int toC, const int col) const
  {
    if(toC < col)
      return toC-1;
    else if(toC == col)
      return toC;
    return toC+1;
  }

  int FissionBoard::findLongestMove(int fromR, int fromC) const
  {
    int longest = 0;
    for (int toR = 0; toR < height; toR++)
    {
      for (int toC = 0; toC < width; toC++)
      {
        if (distance(fromR, fromC, toR, toC) > longest
            && getPiece(fromR, fromC)->isLegalMove(*this, toR, toC))
        {
          longest = distance(fromR, fromC, toR, toC);
        }
      }
    }
    return longest;
  }

  void FissionBoard::makeMove(int fromR, int fromC, int toR, int toC)
  {
    if (isLegalMove(fromR, fromC, toR, toC))
    {
      std::shared_ptr<Piece> moving = getPiece(fromR, fromC);
      moving->makeMove(*this, toR, toC);
      int afterR = getNextR(toR, fromR);
      int afterC = getNextC(toC, fromC);
      std::shared_ptr<Piece> remove = getPiece(afterR, afterC);
      if((*this).inBounds(afterR, afterC) && remove != nullptr)
      {
        if(std::dynamic_pointer_cast<Stone>(remove) && !std::dynamic_pointer_cast<Light>(remove))
        {
          removeStones(toR, toC);
        }
        else
        {
          removePiece(toR, toC);
          removePiece(afterR, afterC);
        }
      }

      // check if further jumps available
      turn = (turn + 1) % 2;
    }
  }

  void FissionBoard::removeStones(int row, int col)
  {
    for(int i = row-1; i <= row+1; i++)
    {
      for(int j = col-1; j <= col+1; j++)
      {
        if(getPiece(i, j) != nullptr)
        {
          removePiece(i,j);
        }
      }
    }
  }

  bool FissionBoard::gameOver() const
  {
    // game is over if no moves for current player
    return findLongestMove() == 0;
  }

  std::string FissionBoard::toString() const
  {
    std::ostringstream os;

    for (int r = 0; r < height; r++)
    {
      for (int c = 0; c < width; c++)
      {
        if (getPiece(r, c) == nullptr)
        {
          if (getBoardColor(r, c) == Color::GRAY)
          {
            os << "  ";
          }
          else
          {
            os << "..";
          }
        }
        else
        {
          os << getPiece(r, c)->toString();
        }
      }
      os << std::endl;
    }

    return os.str();
  }
}

