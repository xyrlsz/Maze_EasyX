#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>

//using namespace std;

struct Cell {
    int row, col;

    Cell(int r, int c) : row(r), col(c) {}
};

// Function to print the maze
//void printMaze(const std::vector<std::vector<int>>& maze) {
//    for (const auto& row : maze) {
//        for (int cell : row) {
//            if (cell == 1) cout << "#";  // Wall
//            else cout << " ";           // Path
//        }
//        cout << endl;
//    }
//}

// Function to check if a cell is within the maze boundaries
bool isValid(int row, int col, int rows, int cols) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

// Function to get neighboring cells
std::vector<Cell> getNeighbors(int row, int col, int rows, int cols) {
    std::vector<Cell> neighbors;
    // Consider four neighboring cells (up, down, left, right)
    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];
        if (isValid(newRow, newCol, rows, cols)) {
            neighbors.emplace_back(newRow, newCol);
        }
    }

    return neighbors;
}

// Prim's algorithm to generate a maze
void generateMaze(std::vector<std::vector<int>>& maze, int rows, int cols, Cell start, Cell end) {
    // Initialize maze with walls
    maze = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 1));

    // Seed for random number generation
    srand(time(0));

    // Mark starting and ending points as paths
    maze[start.row][start.col] = 0;
    maze[end.row][end.col] = 0;

    // Priority queue to store walls
    std::priority_queue<std::pair<int, std::pair<int, int>>> walls;

    // Add neighboring walls of the starting point to the priority queue
    for (const auto& neighbor : getNeighbors(start.row, start.col, rows, cols)) {
        walls.push({ -1 * rand(), {neighbor.row, neighbor.col} });
    }

    // TODO: Implement Prim's algorithm to generate the maze
    while (!walls.empty()) {
        // Your code for the algorithm goes here

        // Hint: Pop a wall, connect the cell to the maze, and add neighboring walls
    }
}

//int main() {
//    int rows = 5;
//    int cols = 5;
//    Cell start(0, 0);
//    Cell end(rows - 1, cols - 1);
//
//    vector<vector<int>> maze;
//
//    generateMaze(maze, rows, cols, start, end);
//
//    cout << "Generated Maze:" << endl;
//    printMaze(maze);
//
//    return 0;
//}
