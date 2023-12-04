#include "recursive_backtracking.h"

void maze::recursive_backtracking::generate(void)
{
    std::mt19937 random_generator(random_device());

    std::uniform_int_distribution<int> random_start_y(1, area.size() - 2);
    std::uniform_int_distribution<int> random_start_x(1, area[0].size() - 2);

    /* ��ʼ�ڿ�϶�� */
    /* ȷ��������������������� */
    crave_passage(random_start_y(random_generator) / 2 * 2 + 1, random_start_x(random_generator) / 2 * 2 + 1);
}

void maze::recursive_backtracking::crave_passage(int y, int x)
{
    /* ����ǰ�����ĸ����� */
    std::vector<int> directions = { north, south, west, east };

    /* ������ҷ��� */
    std::mt19937 random_generator(random_device());
    std::shuffle(directions.begin(), directions.end(), random_generator);

    /* ����������ķ��������� */
    for (int i = 0; i < directions.size(); i++)
    {
        if (north == directions[i])
        {
            /* ����������ߣ���ô�ڿ�϶���ٴε��øú����� */
            if ((y > 2) && (wall == area[y - 2][x]))
            {
                for (int j = 0; j < 3; j++)
                {
                    area[y - 2 + j][x] = hole;
                }
                crave_passage(y - 2, x);
            }
        }
        else if (south == directions[i])
        {
            /* ������������ߣ���ô�ڿ�϶���ٴε��øú����� */
            if (((y + 2) < (area.size() - 1)) && (wall == area[y + 2][x]))
            {
                for (int j = 0; j < 3; j++)
                {
                    area[y + j][x] = hole;
                }
                crave_passage(y + 2, x);
            }
        }
        else if (west == directions[i])
        {
            /* ������������ߣ���ô�ڿ�϶���ٴε��øú����� */
            if ((x > 2) && (wall == area[y][x - 2]))
            {
                for (int j = 0; j < 3; j++)
                {
                    area[y][x - 2 + j] = hole;
                }
                crave_passage(y, x - 2);
            }
        }
        else if (east == directions[i])
        {
            /* ����������ߣ���ô�ڿ�϶���ٴε��øú����� */
            if (((x + 2) < (area[0].size() - 1)) && (wall == area[y][x + 2]))
            {
                for (int j = 0; j < 3; j++)
                {
                    area[y][x + j] = hole;
                }
                crave_passage(y, x + 2);
            }
        }
        else
        {
            /* ʲô�������� */
        }
    }
}