#ifndef GENERATE_H_
#define GENERATE_H_

#include "prim.h"
#include "kruskal.h"   
#include "maze_generator.h"
#include "recursive_division.h" 
#include "recursive_backtracking.h"

// 生成迷宫
class MazeGenerator {
public:
    // prim算法生成迷宫
    std::vector<std::vector<uint32_t>> prim(uint32_t height, uint32_t width,
                                                    uint32_t entranceY, uint32_t entranceX, 
                                                    uint32_t exitY, uint32_t exitX) {
        maze::prim prim(height, width);

        prim.set_cell(entranceY, entranceX, prim.hole);
        prim.set_cell(exitY, exitX, prim.hole);

        prim.generate();

        std::vector<std::vector<uint32_t>> maze = prim.get_maze();

        return maze;
    }
    // 递归回溯算法
    std::vector<std::vector<uint32_t>> recBack(uint32_t height, uint32_t width,
                                                        uint32_t entranceY, uint32_t entranceX, 
                                                        uint32_t exitY, uint32_t exitX) {
        maze::recursive_backtracking m_maze(height, width);
        m_maze.set_cell(entranceY, entranceX, m_maze.hole);
        m_maze.set_cell(exitY, exitX, m_maze.hole);
        m_maze.generate();
        std::vector<std::vector<uint32_t>> maze = m_maze.get_maze();
        return maze;
    }
    // kruskal算法
    std::vector<std::vector<uint32_t>> kruskal(uint32_t height, uint32_t width,
                                                        uint32_t entranceY, uint32_t entranceX, 
                                                        uint32_t exitY, uint32_t exitX){
        maze::kruskal m_maze(height, width);
        m_maze.set_cell(entranceY, entranceX, m_maze.hole);
        m_maze.set_cell(exitY, exitX, m_maze.hole);
        m_maze.generate();
        std::vector<std::vector<uint32_t>> maze = m_maze.get_maze();
        return maze;
    }
    // 递归分割算法
    std::vector<std::vector<uint32_t>> recursive_division(uint32_t height, uint32_t width,
                                                        uint32_t entranceY, uint32_t entranceX, 
                                                        uint32_t exitY, uint32_t exitX){
        maze::recursive_division m_maze(height, width);
        m_maze.set_cell(entranceY, entranceX, m_maze.hole);
        m_maze.set_cell(exitY, exitX, m_maze.hole);
        m_maze.generate();
        std::vector<std::vector<uint32_t>> maze = m_maze.get_maze();
        return maze;
    }
};

#endif