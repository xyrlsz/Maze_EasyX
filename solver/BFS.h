#ifndef BFS_H_
#define BFS_H_
#include <queue>
#include <iostream>
std::queue<std::pair<int, int>> BFS(std::vector<std::vector<uint32_t>> maze, int x1, int y1, int x2, int y2);
#endif