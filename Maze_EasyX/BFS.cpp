#include "BFS.h"

void error_check(std::vector<std::vector<int>> vect, int entrance_y, int entrance_x, int exit_y, int exit_x)
{
    if ((vect.size() <= entrance_y) || (vect[0].size() <= entrance_x) || (vect.size() <= exit_y) || (vect[0].size() <= exit_x))
    {
        throw std::invalid_argument("Out of boundary!");
    }

    //if ((1 != vect[entrance_y][entrance_x]) || (1 != vect[entrance_y][entrance_x]))
    //{
    //    throw std::invalid_argument("The entrance and exit must be holes (0).");
    //}
}


std::queue<std::pair<int, int>> BFS(std::vector<std::vector<int>>& vect, int entrance_y, int entrance_x, int exit_y, int exit_x)
{
    error_check(vect, entrance_y, entrance_x, exit_y, exit_x);
    constexpr int north = 0;
    constexpr int south = 1;
    constexpr int west = 2;
    constexpr int east = 3;
    constexpr int hole = 1;
    constexpr int wall = 0;
    constexpr int solution = 2;
    std::vector<distance> distances;
    int distance_cnt = 3; /* Should be 0, but 0-2 are already used, so it would confuse everything. */
    distances.push_back({ entrance_y, entrance_x });
    bool new_distance = true;
    int y = 0;
    int x = 0;
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(entrance_y, entrance_x));

    /* Walk away from the entrace and save their distance (from the entrance). */
    while (new_distance)
    {
        new_distance = false;
        int distance_max = distances.size();
        distance_cnt++;
        for (int i = 0; i < distance_max; i++)
        {
            y = distances[0].y;
            x = distances[0].x;
            q.push(std::make_pair(y, x));
            vect[y][x] = distance_cnt;
            /* if north is a hole, then save. */
            if ((y > 0) && (hole == vect[y - 1][x]))
            {
                distances.push_back({ y - 1,x });
                new_distance = true;
            }
            /* Ff south is a hole, then save. */
            if (((y + 1) < vect.size()) && (hole == vect[y + 1][x]))
            {
                distances.push_back({ y + 1,x });
                new_distance = true;
            }
            /* if west is a hole, then save. */
            if ((x > 0) && (hole == vect[y][x - 1]))
            {
                distances.push_back({ y,x - 1 });
                new_distance = true;
            }
            /* If east is a hole, then save. */
            if (((x + 1) < vect[0].size()) && (hole == vect[y][x + 1]))
            {
                distances.push_back({ y,x + 1 });
                new_distance = true;
            }

            /* Stop at the end. It could run and check every cell in the maze, but it would be waste of time. */
            if ((y == exit_y) && (x == exit_x))
            {
                new_distance = false;
                break;
            }

            distances.erase(distances.begin());
        }
    }

    /* Walk back from the exit to the entrance. */
    y = exit_y;
    x = exit_x;
    distance_cnt = vect[y][x];

    /* Loop until we aren't at the beginning. */
    while (3 != distance_cnt)
    {
        /* Mark everything as a solution on the way. */
        vect[y][x] = solution;
        distance_cnt--;
        if ((y > 0) && (distance_cnt == vect[y - 1][x]))
        {
            y--;
        }
        else if (((y + 1) < vect.size()) && (distance_cnt == vect[y + 1][x]))
        {
            y++;
        }
        else if ((x > 0) && (distance_cnt == vect[y][x - 1]))
        {
            x--;
        }
        else if (((x + 1) < vect[0].size()) && (distance_cnt == vect[y][x + 1]))
        {
            x++;
        }
    }

    /* Clean up, the output shall only contain walls, holes or solutions. */
    for (int y = 0; y < vect.size(); y++)
    {
        for (int x = 0; x < vect[y].size(); x++)
        {
            if ((wall != vect[y][x]) && (solution != vect[y][x]))
            {
                vect[y][x] = hole;
            }
        }
    }
    return q;
}