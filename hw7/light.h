#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <string>

#include "stone.h"

namespace cs427_527
{
  class FissionBoard;
  
  class Light : public Stone
  {
  public:
    /**
     * Creates a king owned by the given player at the given position.
     *
     * @param p 0 or 1
     * @param r a nonnegative integer
     * @param c a nonnegative integer
     */
    Light(int p, int r, int c);

    /**
     * Destroys this king.
     */
    ~Light();

    /**
     * Returns a printable representation of this stone.
     *
     * @return a printable representation of this stone
     */
    std::string toString() const override;
  };
}
#endif
