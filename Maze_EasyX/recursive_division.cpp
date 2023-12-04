#include "recursive_division.h"

void maze::recursive_division::generate(void)
{
    /* �����������ÿն����ǣ�ʹ�������Ϊ��ǽΪ�߽�Ŀյء� */
    for (int y = 1; y < (area.size() - 1); y++)
    {
        for (int x = 1; x < (area[0].size() - 1); x++)
        {
            area[y][x] = hole;
        }
    }

    /* ��ʼ�������� */
    divide(0, 0, area.size(), area[0].size());
}


void maze::recursive_division::divide(int y, int x, int height, int width)
{
    /*  Mersenne Twister 19937 α������������� */
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

    /* ����ǽ�ķ��� */
    /* �������һ���ϳ���ѡ���෴�ķ��� */
    /* �����Ⱥ͸߶���ȣ������ѡ��һ������ */
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
        /* �ռ䲻�㣬ֹͣ�� */
        if (height < 5)
        {
            return;
        }

        /* ���ѡ��ǽ�Ͷ���λ�á� */
        std::uniform_int_distribution<int> random_wall(2, height - 3);
        std::uniform_int_distribution<int> random_hole(1, width - 2);
        /* ȷ��ǽ��ż�������ϣ��������������ϡ� */
        new_wall = y + (random_wall(random_generator) / 2 * 2);
        new_hole = x + (random_hole(random_generator) / 2 * 2 + 1);

        /* ����ǽ�� */
        for (int i = x; i < (x + width - 1); i++)
        {
            area[new_wall][i] = wall;
        }
        /* ���ö��� */
        area[new_wall][new_hole] = hole;

        /* �����´ε�������ֵ�� */
        new_height = new_wall - y + 1;
        new_width = width;
        /* �ԳƵ�λ�á�'ǽ����һ�ࡣ' */
        y_pair = new_wall;
        x_pair = x;
        new_height_pair = y + height - new_wall;
        new_width_pair = width;
    }
    else if (vertical == orientation)
    {
        /* �ռ䲻�㣬ֹͣ�� */
        if (width < 5)
        {
            return;
        }

        /* ���ѡ��ǽ�Ͷ���λ�á� */
        std::uniform_int_distribution<int> random_wall(2, width - 3);
        std::uniform_int_distribution<int> random_hole(1, height - 2);
        /* ȷ��ǽ��ż�������ϣ��������������ϡ� */
        new_wall = x + (random_wall(random_generator) / 2 * 2);
        new_hole = y + (random_hole(random_generator) / 2 * 2 + 1);

        /* ����ǽ�� */
        for (int i = y; i < (y + height - 1); i++)
        {
            area[i][new_wall] = wall;
        }
        /* ���ö��� */
        area[new_hole][new_wall] = hole;

        /* �����´ε�������ֵ�� */
        new_height = height;
        new_width = new_wall - x + 1;
        /* �ԳƵ�λ�á�'ǽ����һ�ࡣ' */
        y_pair = y;
        x_pair = new_wall;
        new_height_pair = height;
        new_width_pair = x + width - new_wall;
    }
    else
    {
        /* ʲô�������� */
    }

    /* �ٴε��ú����� */
    divide(y, x, new_height, new_width);
    /* ��û��λ��ʱ������'��һ��'�� */
    divide(y_pair, x_pair, new_height_pair, new_width_pair);
}