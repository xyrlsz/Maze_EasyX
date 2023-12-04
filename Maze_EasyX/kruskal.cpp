#include "kruskal.h"
#include <random>

void maze::Kruskal::generate(void)
{
    std::mt19937 random_generator(random_device());

    sets.resize(area.size());
    for (int y = 0; y < area.size(); y++)
    {
        sets[y].resize(area[y].size());
    }

    /* �洢ÿ�������ƶ��� y��x ���ꡣͬʱ���ò�ͬ��ֵ��� sets�� */
    std::vector<element> elements;
    int i = 1;
    for (int y = 1; y < (sets.size() - 1); y += 2)
    {
        for (int x = 1; x < (sets[0].size() - 1); x += 2)
        {
            if ((y + 2) < (sets.size() - 1))
            {
                elements.push_back({ y, x, vertical });
            }
            if ((x + 2) < (sets[0].size() - 1))
            {
                elements.push_back({ y, x, horizontal });
            }
            sets[y][x] = i;
            i++;
        }
    }

    /* ���� elements ������ */
    std::shuffle(elements.begin(), elements.end(), random_generator);

    /* ֱ��û��Ԫ��ʣ��Ϊֹ�� */
    while (elements.size())
    {
        int y = elements[elements.size() - 1].y;
        int x = elements[elements.size() - 1].x;
        int orientation = elements[elements.size() - 1].orientation;
        elements.pop_back();

        if (horizontal == orientation)
        {
            /* ����������ϲ�ͬ����ʹ������ͬ��������һ��ͨ���� */
            if (sets[y][x + 2] != sets[y][x])
            {
                replace(sets[y][x + 2], sets[y][x]);
                for (int j = 0; j < 3; j++)
                {
                    area[y][x + j] = hole;
                }
            }
        }
        else if (vertical == orientation)
        {
            /* ����������ϲ�ͬ����ʹ������ͬ��������һ��ͨ���� */
            if (sets[y + 2][x] != sets[y][x])
            {
                replace(sets[y + 2][x], sets[y][x]);
                for (int j = 0; j < 3; j++)
                {
                    area[y + j][x] = hole;
                }
            }
        }
        else
        {
            /* ʲô�������� */
        }
    }
}

void maze::Kruskal::replace(int set_to_replace, int sample_set)
{
    for (int search_y = 1; search_y < (sets.size() - 1); search_y += 2)
    {
        for (int search_x = 1; search_x < (sets[0].size() - 1); search_x += 2)
        {
            if (sets[search_y][search_x] == set_to_replace)
            {
                sets[search_y][search_x] = sample_set;
            }
        }
    }
}