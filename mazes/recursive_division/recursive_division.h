#ifndef RECURSIVE_DIVISION_H_
#define RECURSIVE_DIVISION_H_

#include "maze_generator.h"

namespace maze
{
  class recursive_division: public maze_generator
  {
    public:
      using maze_generator::maze_generator;
      void generate(void);

    private:
      void divide(uint32_t y, uint32_t x, uint32_t height, uint32_t width);
  };
}

#endif 

