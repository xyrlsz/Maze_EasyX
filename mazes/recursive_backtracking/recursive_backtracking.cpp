#include "recursive_backtracking.h"

void maze::recursive_backtracking::generate(void)
{
  std::mt19937 random_generator(random_device());

  std::uniform_int_distribution<uint32_t> random_start_y(1u, area.size()-2u);
  std::uniform_int_distribution<uint32_t> random_start_x(1u, area[0u].size()-2u);

  /* 开始挖空隙。 */
  /* 确保两个随机数都是奇数。 */
  crave_passage(random_start_y(random_generator)/2u*2u+1u, random_start_x(random_generator)/2u*2u+1u);
}

void maze::recursive_backtracking::crave_passage(uint32_t y, uint32_t x)
{
  /* 可以前进的四个方向。 */
  std::vector<uint32_t> directions = {north, south, west, east};
  
  /* 随机打乱方向。 */
  std::mt19937 random_generator(random_device());
  std::shuffle(directions.begin(), directions.end(), random_generator);

  /* 遍历随机填充的方向向量。 */
  for (uint32_t i = 0u; i < directions.size(); i++)
  {
    if (north == directions[i])
    {
      /* 如果可以向北走，那么挖空隙并再次调用该函数。 */
      if ((y > 2u) && (wall == area[y-2u][x]))
      {
        for (uint32_t j = 0u; j < 3u; j++)
        {
          area[y-2u+j][x] = hole;
        }
        crave_passage(y-2u, x);
      }
    }
    else if (south == directions[i])
    {
      /* 如果可以向南走，那么挖空隙并再次调用该函数。 */
      if (((y+2u) < (area.size()-1u)) && (wall == area[y+2u][x]))
      {
        for (uint32_t j = 0u; j < 3u; j++)
        {
          area[y+j][x] = hole;
        }
        crave_passage(y+2u, x);
      }
    }
    else if (west == directions[i])
    {
      /* 如果可以向西走，那么挖空隙并再次调用该函数。 */
      if ((x > 2u) && (wall == area[y][x-2]))
      {
        for (uint32_t j = 0u; j < 3u; j++)
        {
          area[y][x-2u+j] = hole;
        }
        crave_passage(y, x-2u);
      }
    }
    else if (east == directions[i])
    {
      /* 如果可以向东走，那么挖空隙并再次调用该函数。 */
      if (((x+2u) < (area[0u].size()-1u)) && (wall == area[y][x+2u]))
      {
        for (uint32_t j = 0u; j < 3u; j++)
        {
          area[y][x+j] = hole;
        }
        crave_passage(y, x+2u);
      }
    }
    else
    {
      /* 什么都不做。 */
    }
  }
}