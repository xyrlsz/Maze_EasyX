#pragma once
#ifndef RECURSIVE_DIVISION_H_
#define RECURSIVE_DIVISION_H_

#include "maze_generator.h"

namespace maze
{
    class recursive_division : public maze_generator
    {
    public:
        using maze_generator::maze_generator;
        void generate(void);

    private:
        void divide(int y, int x, int height, int width);
    };
}

#endif 

