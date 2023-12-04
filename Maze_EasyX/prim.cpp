#include "prim.h"

// ʹ��prim�㷨�����Թ�
void maze::prim::generate(void)
{
    std::mt19937 random_generator(random_device());
    // ���ѡ����ʼ��
    std::uniform_int_distribution<int> random_start_y(1, area.size() - 2);
    std::uniform_int_distribution<int> random_start_x(1, area[0].size() - 2);
    // ���ѡ����
    std::uniform_int_distribution<int> random_dir(north, east);

    // ȷ�����ɵ������������
    mark(random_start_y(random_generator) / 2 * 2 + 1, random_start_x(random_generator) / 2 * 2 + 1);

    // ֱ��frontiersΪ��
    while (!frontiers.empty())
    {
        bool possible_to_carve = false;

        /* ��frontiers�б������ѡ��һ��ǰ�� */
        std::uniform_int_distribution<int> random_frontier(0, frontiers.size() - 1);
        int next_frontier = random_frontier(random_generator);
        int y = frontiers[next_frontier].y;
        int x = frontiers[next_frontier].x;
        /* ���б����Ƴ���ǰ�� */
        frontiers.erase(frontiers.begin() + next_frontier);

        /* ������ĳһ���������ƶ���ֱ���ҵ����еķ���Ϊֹ�� */
        while (!possible_to_carve)
        {
            int direction = random_dir(random_generator);
            if (north == direction)
            {
                /* ����������ƶ������ڵ�һ��������ֹͣѭ�� */
                if ((y > 2) && (hole == area[y - 2][x]))
                {
                    possible_to_carve = true;
                    area[y - 1][x] = hole;
                }
            }
            else if (south == direction)
            {
                /* ������������ƶ������ڵ�һ��������ֹͣѭ�� */
                if (((y + 2) < (area.size() - 1)) && (hole == area[y + 2][x]))
                {
                    possible_to_carve = true;
                    area[y + 1][x] = hole;
                }
            }
            else if (west == direction)
            {
                /* ������������ƶ������ڵ�һ��������ֹͣѭ�� */
                if ((x > 2) && (hole == area[y][x - 2]))
                {
                    possible_to_carve = true;
                    area[y][x - 1] = hole;
                }
            }
            else if (east == direction)
            {
                /* ����������ƶ������ڵ�һ��������ֹͣѭ�� */
                if (((x + 2) < (area[0].size() - 1)) && (hole == area[y][x + 2]))
                {
                    possible_to_carve = true;
                    area[y][x + 1] = hole;
                }
            }
        }

        /* �����µ�ǰ�� */
        mark(y, x);
    }
}

// ��[y,x]���괦����һ����������ÿ���������ڵĵ�Ԫ��ӵ�frontiers�б�
void maze::prim::mark(int y, int x)
{
    // ���Ϊ��
    area[y][x] = hole;
    /* ������ĵ�Ԫ����Ϊǰ�ر��棨����������߽磩 */
    if ((y >= 3) && (wall == area[y - 2][x]))
    {
        area[y - 2][x] = frontier;
        frontiers.push_back({ y - 2,x });
    }
    /* ������ĵ�Ԫ����Ϊǰ�ر��棨����������߽磩 */
    if (((y + 2) <= area.size() - 2) && (wall == area[y + 2][x]))
    {
        area[y + 2][x] = frontier;
        frontiers.push_back({ y + 2,x });
    }
    /* ������ĵ�Ԫ����Ϊǰ�ر��棨����������߽磩 */
    if ((x >= 3) && (wall == area[y][x - 2]))
    {
        area[y][x - 2] = frontier;
        frontiers.push_back({ y,x - 2 });
    }
    /* ������ĵ�Ԫ����Ϊǰ�ر��棨����������߽磩 */
    if (((x + 2) <= area[0].size() - 2) && (wall == area[y][x + 2]))
    {
        area[y][x + 2] = frontier;
        frontiers.push_back({ y,x + 2 });
    }
}