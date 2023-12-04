#pragma once
#ifndef MAZE_GENERATOR_H_
#define MAZE_GENERATOR_H_

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>

namespace maze
{
    class maze_generator
    {
    public:
        maze_generator(int height, int width) {

            std::vector < std::vector<int>>tmp(height,std::vector<int>(width, wall));
            this->area = tmp;
        }

        static constexpr int wall = 0;
        static constexpr int hole = 1;
        static constexpr int solution = 2;

        void set_cell(int y, int x, int value);
        int get_cell(int y, int x);

        std::vector<std::vector<int>> get_maze(void);
        void set_maze(std::vector<std::vector<int>> vect);

        void reshape(int new_height, int new_width);

        int get_height(void);
        int get_width(void);

    protected:
        std::random_device random_device;
        static constexpr int vertical = 0;
        static constexpr int horizontal = 1;
        static constexpr uint8_t north = 0;
        static constexpr uint8_t south = 1;
        static constexpr uint8_t west = 2;
        static constexpr uint8_t east = 3;

        std::vector<std::vector<int>> area;


    };
}

#endif 

