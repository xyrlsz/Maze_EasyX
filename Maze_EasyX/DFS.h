#pragma once

#ifndef DFS_H_
#define DFS_H_
#include <iostream>
#include <vector>
#include <queue>

std::queue<std::pair<int, int>> DFS(std::vector<std::vector<int>> maze, int x1, int y1, int x2, int y2);
#endif 

