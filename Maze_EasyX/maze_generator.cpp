#include "maze_generator.h"

// 生成一张迷宫
//maze::maze_generator::maze_generator(int height, int width)
//{
//    if ((!(height % 2)) || (!(width % 2)))
//    {
//        throw std::invalid_argument("Height and width must be odd numbers!");
//    }
//
//    // 创造一张二维图，且全部设置墙
//    //area.resize(height);
//    //std::vector<std::vector<int>> tmp(int(height), std::vector<int>(int(width), 0));
//
//    for (int y = 0; y < height; y++)
//    {
//        area[y].resize(width);
//        for (int x = 0; x < width; x++)
//        {
//            area[y][x] = wall;
//        }
//    }
//}

// 手动改变单元值
void maze::maze_generator::set_cell(int y, int x, int value)
{
    if ((area.size() <= y) || (area[y].size() <= x))
    {
        throw std::invalid_argument("Out of boundary!");
    }
    else if ((wall != value) && (hole != value))
    {
        throw std::invalid_argument("The input can only contain 0 or 1.");
    }
    else
    {
        area[y][x] = value;
    }
}

int maze::maze_generator::get_cell(int y, int x)
{
    return area[y][x];
}

std::vector<std::vector<int>> maze::maze_generator::get_maze(void)
{
    return area;
}

// 覆盖当前迷宫
void maze::maze_generator::set_maze(std::vector<std::vector<int>> vect)
{
    if ((vect.size() != area.size()) || (vect[0].size() != area[0].size()))
    {
        throw std::invalid_argument("Wrong size!");
    }
    else
    {
        for (int y = 0; y < vect.size(); y++)
        {
            for (int x = 0; x < vect[y].size(); x++)
            {
                if ((wall != vect[y][x]) && (hole != vect[y][x]))
                {
                    throw std::invalid_argument("The input can only contain 0 or 1.");
                }
                else
                {
                    area[y][x] = vect[y][x];
                }
            }
        }
    }
}

// 改变迷宫形状
void maze::maze_generator::reshape(int height, int width)
{
    /* Make sure, that the dimensions are odd numbers, otherwise the maze would look strange. */
    if ((!(height % 2)) || (!(width % 2)))
    {
        throw std::invalid_argument("Height and width must be odd numbers!");
    }

    area.resize(height);
    for (int y = 0; y < height; y++)
    {
        area[y].resize(width);
    }
}

// 返回迷宫的高
int maze::maze_generator::get_height(void)
{
    return area.size();
}

// 返回迷宫的宽
int maze::maze_generator::get_width(void)
{
    return area[0].size();
}

