/*
 * CS427 Assignment 2
 *
 * Author: Melina Delgado
 * Date: 9/27 11:59pm
 *
 * mainSpinout.c
 *
 */

#include "spinout.h"
#include <iostream>
#include <string>
#include <stdbool.h>
#include <cstring>

using std::cerr;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char **argv)
{
  bool interactive = false;
  bool config_given = false;
  int numbers = 0;

  if(argc > 1)
  {
    if(!strcmp(argv[1],"-i"))
    {
      interactive = true;
      if(argc>3)
      {
        cerr << "too many args" << endl;
        exit(1);
      }
      if(argc == 3)
      {
        if(strlen(argv[2]) == cs427_527::SpinOut::SIZE)
        {
          for(unsigned int i = 0; i < strlen(argv[2]); i++)
          {
            if((argv[2][i] == '-') || (argv[2][i] == '/'))
            {
              config_given = true;
            }
            else
            {
              cerr << "invalid configuration" << endl;
              exit(1);
            }
          }
        }
      }
    }
    else if(strlen(argv[1]) == 7)
    {
      for(unsigned int i = 0; i < strlen(argv[1]); i++)
      {
        if((argv[1][i] == '-') || (argv[1][i] == '/'))
        {
          config_given = true;
        }
        else
        {
          cerr << "invalid configuration" << endl;
          exit(1);
        }
      }

      if(argc > 2)
      {
        for(int i=2; i < argc; i++)
        {
          long int input = strtol(argv[i],NULL,10);
          if((input < 0) || (input > 6))
          {
            cerr << "Invalid index input" << endl;
            exit(1);
          }
          if((input == 0) && strcmp(argv[i], "0"))
          {
            cerr << "invalid index input" << endl;
            exit(1);
          }
          numbers++;
        }
      }
      else
      {
        cerr << "no number sequence given" << endl;
        exit(1);
      }
    }
    else
    {
      for(int i=1; i < argc; i++)
      {
        long int input = strtol(argv[i],NULL,10);
        if((input < 0) || (input > 6))
        {
          cerr << "Invalid index input" << endl;
          exit(1);
        }
        if((input == 0) && strcmp(argv[i], "0"))
        {
          cerr << "invalid index input" << endl;
          exit(1);
        }
        numbers++;
      }
    }
  }
  else
  {
    cerr << "spinout needs arguments" <<endl;
  }

  int index;
  std::string printstr;
  if(interactive)
  {
    if(config_given)
    {
      cout << argv[2] << endl;
      cs427_527::SpinOut config(argv[2]);

      while((cin >> index)&&(!cin.eof())&&((index < 7)&&(index>0)))
      {
        if(config.isLegalMove(index))
        {
          config.makeMove(index);
          printstr = config.toString();
          cout << printstr << endl;
          if(config.isSolved())
          {
            cout << config.totalMoves() << " moves" << endl;
            break;
          }
        }
        else
        {
          cout << "illegal move" << endl;
        }

      }
    }
    else
    {
      cs427_527::SpinOut config;
      printstr = 
        config.toString();
      cout << printstr << endl;

      while((cin >> index)&&(!(cin.eof()))&&((index < 7)&&(index>0)))
      {
        if(config.isLegalMove(index))
        {
          config.makeMove(index);
          printstr = config.toString();
          cout << printstr << endl;
        }
        else
        {
          cout << "illegal move" << endl;
        }

        if(config.isSolved())
        {
          cout << config.totalMoves() << " moves" << endl;
          break;
        }
      }
    }
  }
  else //not interactive
  {
    if(config_given)
    {
      cs427_527::SpinOut config(argv[1]);
      int i = 2;

      while((i-1) <= numbers)
      {
        index = strtol(argv[i],NULL,10);
        if(config.isLegalMove(index))
        {
          config.makeMove(index);
        }
        else
        {
          cout << "SpinOut: illegal move " << index << " in position " << i-1 << " for " << config.toString() << endl;
          exit(1);
        }
        i++;
      }
      if(config.isSolved())
      {
        cout << "SOLVED" << endl;
      }
      else
      {
        cout << config.toString() << endl;
      }
    }
    else
    {
      cs427_527::SpinOut config;
      int i = 1;
      while(i <= numbers)
      {
        index = strtol(argv[i], NULL, 10);
        if(config.isLegalMove(index))
        {
          config.makeMove(index);
        }
        else
        {
          cout << "SpinOut: illegal move " << index << " in position " << i << " for " << config.toString() << endl;
          exit(1);
        }
        i++;
      }
      if(config.isSolved())
      {
        cout << "SOLVED" << endl;
      }
      else
      {
        cout << config.toString() << endl;
      }
    }
  }
}
