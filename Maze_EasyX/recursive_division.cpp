#include "recursive_division.h"

void maze::recursive_division::generate(void)
{
    /* 将中心区域用空洞覆盖，使得区域成为以墙为边界的空地。 */
    for (int y = 1; y < (area.size() - 1); y++)
    {
        for (int x = 1; x < (area[0].size() - 1); x++)
        {
            area[y][x] = hole;
        }
    }

    /* 开始划分区域。 */
    divide(0, 0, area.size(), area[0].size());
}


void maze::recursive_division::divide(int y, int x, int height, int width)
{
    /*  Mersenne Twister 19937 伪随机数生成器。 */
    std::mt19937 random_generator(random_device());

    int orientation = horizontal;
    int new_wall = 0;
    int new_hole = 0;
    int new_height = 0;
    int new_width = 0;
    int y_pair = 0;
    int x_pair = 0;
    int new_height_pair = 0;
    int new_width_pair = 0;

    /* 决定墙的方向。 */
    /* 如果其中一个较长，选择相反的方向。 */
    /* 如果宽度和高度相等，则随机选择一个方向。 */
    if (width < height)
    {
        orientation = horizontal;
    }
    else if (width > height)
    {
        orientation = vertical;
    }
    else
    {
        std::uniform_int_distribution<int> random_dir(vertical, horizontal);
        orientation = random_dir(random_generator);
    }

    if (horizontal == orientation)
    {
        /* 空间不足，停止。 */
        if (height < 5)
        {
            return;
        }

        /* 随机选择墙和洞的位置。 */
        std::uniform_int_distribution<int> random_wall(2, height - 3);
        std::uniform_int_distribution<int> random_hole(1, width - 2);
        /* 确保墙在偶数坐标上，洞在奇数坐标上。 */
        new_wall = y + (random_wall(random_generator) / 2 * 2);
        new_hole = x + (random_hole(random_generator) / 2 * 2 + 1);

        /* 放置墙。 */
        for (int i = x; i < (x + width - 1); i++)
        {
            area[new_wall][i] = wall;
        }
        /* 放置洞。 */
        area[new_wall][new_hole] = hole;

        /* 计算下次迭代的新值。 */
        new_height = new_wall - y + 1;
        new_width = width;
        /* 对称的位置。'墙的另一侧。' */
        y_pair = new_wall;
        x_pair = x;
        new_height_pair = y + height - new_wall;
        new_width_pair = width;
    }
    else if (vertical == orientation)
    {
        /* 空间不足，停止。 */
        if (width < 5)
        {
            return;
        }

        /* 随机选择墙和洞的位置。 */
        std::uniform_int_distribution<int> random_wall(2, width - 3);
        std::uniform_int_distribution<int> random_hole(1, height - 2);
        /* 确保墙在偶数坐标上，洞在奇数坐标上。 */
        new_wall = x + (random_wall(random_generator) / 2 * 2);
        new_hole = y + (random_hole(random_generator) / 2 * 2 + 1);

        /* 放置墙。 */
        for (int i = y; i < (y + height - 1); i++)
        {
            area[i][new_wall] = wall;
        }
        /* 放置洞。 */
        area[new_hole][new_wall] = hole;

        /* 计算下次迭代的新值。 */
        new_height = height;
        new_width = new_wall - x + 1;
        /* 对称的位置。'墙的另一侧。' */
        y_pair = y;
        x_pair = new_wall;
        new_height_pair = height;
        new_width_pair = x + width - new_wall;
    }
    else
    {
        /* 什么都不做。 */
    }

    /* 再次调用函数。 */
    divide(y, x, new_height, new_width);
    /* 当没有位置时，进入'另一侧'。 */
    divide(y_pair, x_pair, new_height_pair, new_width_pair);
}