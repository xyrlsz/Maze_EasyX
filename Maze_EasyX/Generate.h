#pragma once
#ifndef GENERATE_H_
#define GENERATE_H_

#include "prim.h"
#include "kruskal.h"   
#include "maze_generator.h"
#include "recursive_division.h" 
#include "recursive_backtracking.h"

// �����Թ�
class MazeGenerator {
public:
    // prim�㷨�����Թ�

    std::vector<std::vector<int>> prim(int height, int width,
        int entranceY, int entranceX,
        int exitY, int exitX) {
        maze::prim prim(height, width);

        prim.set_cell(entranceY, entranceX, prim.hole);
        prim.set_cell(exitY, exitX, prim.hole);

        prim.generate();

        std::vector<std::vector<int>> maze = prim.get_maze();

        return maze;
    }
    // �ݹ�����㷨
    std::vector<std::vector<int>> recBack(int height, int width,
        int entranceY, int entranceX,
        int exitY, int exitX) {
        maze::recursive_backtracking m_maze(height, width);
        m_maze.set_cell(entranceY, entranceX, m_maze.hole);
        m_maze.set_cell(exitY, exitX, m_maze.hole);
        m_maze.generate();
        std::vector<std::vector<int>> maze = m_maze.get_maze();
        return maze;
    }
    // kruskal�㷨
    std::vector<std::vector<int>> Kruskal(int height, int width,
        int entranceY, int entranceX,
        int exitY, int exitX) {
        maze::Kruskal m_maze(height, width);
        m_maze.set_cell(entranceY, entranceX, m_maze.hole);
        m_maze.set_cell(exitY, exitX, m_maze.hole);
        m_maze.generate();
        std::vector<std::vector<int>> maze = m_maze.get_maze();
        return maze;
    }
    // �ݹ�ָ��㷨
    std::vector<std::vector<int>> recursive_division(int height, int width,
        int entranceY, int entranceX,
        int exitY, int exitX) {
        maze::recursive_division m_maze(height, width);
        m_maze.set_cell(entranceY, entranceX, m_maze.hole);
        m_maze.set_cell(exitY, exitX, m_maze.hole);
        m_maze.generate();
        std::vector<std::vector<int>> maze = m_maze.get_maze();
        return maze;
    }
private:

};

#endif