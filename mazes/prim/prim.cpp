#include "prim.h"

// 使用prim算法生成迷宫
void maze::prim::generate(void)
{
  std::mt19937 random_generator(random_device());
  // 随机选择起始点
  std::uniform_int_distribution<uint32_t> random_start_y(1u, area.size()-2u);
  std::uniform_int_distribution<uint32_t> random_start_x(1u, area[0u].size()-2u);
  // 随机选择方向
  std::uniform_int_distribution<uint32_t> random_dir(north, east);

  // 确保生成的随机数是奇数
  mark(random_start_y(random_generator)/2u*2u+1u, random_start_x(random_generator)/2u*2u+1u);

  // 直到frontiers为空
  while(!frontiers.empty())
  {
    bool possible_to_carve = false;

    /* 从frontiers列表中随机选择一个前沿 */
    std::uniform_int_distribution<uint32_t> random_frontier(0u, frontiers.size()-1u);
    uint32_t next_frontier = random_frontier(random_generator);
    uint32_t y = frontiers[next_frontier].y;
    uint32_t x = frontiers[next_frontier].x;
    /* 从列表中移除该前沿 */
    frontiers.erase(frontiers.begin()+next_frontier);

    /* 尝试在某一个方向上移动（直到找到可行的方向为止） */
    while(!possible_to_carve)
    {
      uint32_t direction = random_dir(random_generator);
      if (north == direction)
      {
        /* 如果可以向北移动，就挖掉一个洞，并停止循环 */
        if ((y > 2u) && (hole == area[y-2u][x]))
        {
          possible_to_carve = true;
          area[y-1u][x] = hole;
        }
      }
      else if (south == direction)
      {
        /* 如果可以向南移动，就挖掉一个洞，并停止循环 */
        if (((y+2u) < (area.size()-1u)) && (hole == area[y+2u][x]))
        {
          possible_to_carve = true;
          area[y+1u][x] = hole;
        }
      }
      else if (west == direction)
      {
        /* 如果可以向西移动，就挖掉一个洞，并停止循环 */
        if ((x > 2u) && (hole == area[y][x-2]))
        {
          possible_to_carve = true;
          area[y][x-1u] = hole;
        }
      }
      else if (east == direction)
      {
        /* 如果可以向东移动，就挖掉一个洞，并停止循环 */
        if (((x+2u) < (area[0u].size()-1u)) && (hole == area[y][x+2u]))
        {
          possible_to_carve = true;
          area[y][x+1u] = hole;
        }
      }
    }

    /* 创建新的前沿 */
    mark(y, x);
  }
}

// 在[y,x]坐标处设置一个洞，并将每个可能相邻的单元添加到frontiers列表
void maze::prim::mark(uint32_t y, uint32_t x)
{
  // 标记为洞
  area[y][x] = hole;
  /* 将北面的单元格作为前沿保存（如果不超出边界） */
  if ((y >= 3u) && (wall == area[y-2u][x]))
  {
    area[y-2u][x] = frontier;
    frontiers.push_back({y-2u,x});
  }
  /* 将南面的单元格作为前沿保存（如果不超出边界） */
  if (((y+2u) <= area.size()-2u) && (wall == area[y+2u][x]))
  {
    area[y+2u][x] = frontier;
    frontiers.push_back({y+2u,x});
  }
  /* 将西面的单元格作为前沿保存（如果不超出边界） */
  if ((x >= 3u) && (wall == area[y][x-2u]))
  {
    area[y][x-2u] = frontier;
    frontiers.push_back({y,x-2u});
  }
  /* 将东面的单元格作为前沿保存（如果不超出边界） */
  if (((x+2u) <= area[0u].size()-2u) && (wall == area[y][x+2u]))
  {
    area[y][x+2u] = frontier;
    frontiers.push_back({y,x+2u});
  }
}