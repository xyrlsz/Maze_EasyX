#include "maze_generator.h"

// 生成一张迷宫
maze::maze_generator::maze_generator(uint32_t height, uint32_t width)
{
  if ((!(height%2u)) || (!(width%2u)))
  {
    throw std::invalid_argument("Height and width must be odd numbers!");
  }

  // 创造一张二维图，且全部设置墙
  area.resize(height);
  for (uint32_t y = 0u; y < height; y++)
  {
    area[y].resize(width);
    for (uint32_t x = 0u; x < width; x++)
    {
      area[y][x] = wall;
    }
  }
}

// 手动改变单元值
void maze::maze_generator::set_cell(uint32_t y, uint32_t x, uint32_t value)
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

uint32_t maze::maze_generator::get_cell(uint32_t y, uint32_t x)
{
  return area[y][x];
}

std::vector<std::vector<uint32_t>> maze::maze_generator::get_maze(void)
{
  return area;
}

// 覆盖当前迷宫
void maze::maze_generator::set_maze(std::vector<std::vector<uint32_t>> vect)
{
  if ((vect.size() != area.size()) || (vect[0u].size() != area[0u].size()))
  {
    throw std::invalid_argument("Wrong size!");
  }
  else
  { 
    for (uint32_t y = 0u; y < vect.size(); y++)
    {
      for (uint32_t x = 0u; x < vect[y].size(); x++)
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
void maze::maze_generator::reshape(uint32_t height, uint32_t width)
{
  /* Make sure, that the dimensions are odd numbers, otherwise the maze would look strange. */
  if ((!(height%2u)) || (!(width%2u)))
  {
    throw std::invalid_argument("Height and width must be odd numbers!");
  }

  area.resize(height);
  for (uint32_t y = 0u; y < height; y++)
  {
    area[y].resize(width);
  }
}

// 返回迷宫的高
uint32_t maze::maze_generator::get_height(void)
{
  return area.size();
}

// 返回迷宫的宽
uint32_t maze::maze_generator::get_width(void)
{
  return area[0u].size();
}

