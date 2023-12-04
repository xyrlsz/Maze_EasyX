#include "kruskal.h"

void maze::kruskal::generate(void)
{
  std::mt19937 random_generator(random_device());

  sets.resize(area.size());
  for (uint32_t y = 0u; y < area.size(); y++)
  {
    sets[y].resize(area[y].size());
  }

  /* 存储每个可能移动的 y、x 坐标。同时，用不同的值填充 sets。 */
  std::vector<element> elements;
  uint32_t i = 1u;
  for (uint32_t y = 1u; y < (sets.size()-1u); y+=2u)
  {
    for (uint32_t x = 1u; x < (sets[0u].size()-1u); x+=2u)
    {
      if ((y+2u) < (sets.size()-1u))
      {
        elements.push_back({y, x, vertical});
      }
      if ((x+2u) < (sets[0u].size()-1u))
      {
        elements.push_back({y, x, horizontal});
      }
      sets[y][x] = i;
      i++;
    }
  }

  /* 打乱 elements 向量。 */
  std::shuffle(elements.begin(), elements.end(), random_generator);

  /* 直到没有元素剩下为止。 */
  while(elements.size())
  {
    uint32_t y = elements[elements.size()-1u].y;
    uint32_t x = elements[elements.size()-1u].x;
    uint32_t orientation = elements[elements.size()-1u].orientation;
    elements.pop_back();    

    if (horizontal == orientation)
    {
      /* 如果两个集合不同，则使它们相同，并开凿一个通道。 */
      if (sets[y][x+2u] != sets[y][x])
      {
        replace(sets[y][x+2u], sets[y][x]);
        for (uint32_t j = 0u; j < 3u; j++)
        {
          area[y][x+j] = hole;
        }
      }
    }
    else if (vertical == orientation)
    {
      /* 如果两个集合不同，则使它们相同，并开凿一个通道。 */
      if (sets[y+2u][x] != sets[y][x])
      {
        replace(sets[y+2u][x], sets[y][x]);
        for (uint32_t j = 0u; j < 3u; j++)
        {
          area[y+j][x] = hole;
        }
      }
    }
    else
    {
      /* 什么都不做。 */
    }
  }
}

void maze::kruskal::replace(uint32_t set_to_replace, uint32_t sample_set)
{
  for (uint32_t search_y = 1u; search_y < (sets.size()-1u); search_y+=2u)
  {
    for (uint32_t search_x = 1u; search_x < (sets[0u].size()-1u); search_x+=2u)
    {
      if (sets[search_y][search_x] == set_to_replace)
      {
        sets[search_y][search_x] = sample_set;
      }
    }
  }
}