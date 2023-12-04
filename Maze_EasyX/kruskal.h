#pragma once
#ifndef KRUSKAL_H_
#define KRUSKAL_H_

#include "maze_generator.h"

namespace maze
{
    class Kruskal : public maze_generator
    {
    public:
        using maze_generator::maze_generator;
        void generate(void);

    private:
        struct element {
            int y;
            int x;
            int orientation;
        };

        std::vector<std::vector<int>> sets;

        void replace(int set_to_replace, int sample_set);
    };
}

#endif /* KRUSKAL_H_ */

