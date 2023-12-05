#pragma once
#ifndef BFS_H_
#define BFS_H_
#include <queue>
#include <vector>
#include <iostream>
struct distance {
    int y;
    int x;
};
void error_check(std::vector<std::vector<int>> vect, int entrance_y, int entrance_x, int exit_y, int exit_x);
std::queue<std::pair<int, int>> BFS(std::vector<std::vector<int>>& maze, int x1, int y1, int x2, int y2);
#endif