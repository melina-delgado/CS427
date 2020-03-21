#include <algorithm>
#include <cctype>

#include "piece.h"
#include "light.h"
#include "stone.h"

namespace cs427_527
{
  Light::Light(int p, int r, int c)
    : Stone(p, r, c)
  {
  }

  Light::~Light()
  {
  }

  std::string Light::toString() const
  {
    // convert base class's result to upper case
    std::string result = Stone::toString();
    std::transform(result.begin(), result.end(), result.begin(), tolower);
    return result;
  }
}

