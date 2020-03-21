/* puzzlemove.h
 *
 * Melina Delgado
 * 
 * CS427
 */

#ifndef __PUZZLEMOVE_H__
#define __PUZZLEMOVE_H__

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>

namespace cs427_527
{
  class PuzzleMove
  {
    public:
      PuzzleMove(int);
      PuzzleMove(int, int, int, int);
      std::string toString() const;
      std::vector<int> moves;
  };
  std::ostream& operator<<(std::ostream&, const PuzzleMove&);
}

#endif
