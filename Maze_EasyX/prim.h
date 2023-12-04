#pragma once
#ifndef PRIM_H_
#define PRIM_H_

#include "maze_generator.h"

namespace maze
{
    class prim : public maze_generator
    {
    public:
        using maze_generator::maze_generator;
        void generate(void);

    private:
        static constexpr int frontier = 2; /**< Third option after wall and hole. */

        struct frontier_location {
            int y;
            int x;
        };

        std::vector<frontier_location> frontiers;

        void mark(int y, int x);
    };
}

#endif /* PRIM_H_ */