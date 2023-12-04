#ifndef KRUSKAL_H_
#define KRUSKAL_H_

#include "maze_generator.h"

namespace maze
{
  class kruskal: public maze_generator
  {
    public:
      using maze_generator::maze_generator;
      void generate(void);

    private:
      struct element {
        uint32_t y;
        uint32_t x;
        uint32_t orientation;
      };

      std::vector<std::vector<uint32_t>> sets;

      void replace(uint32_t set_to_replace, uint32_t sample_set);
  };
}

#endif /* KRUSKAL_H_ */

