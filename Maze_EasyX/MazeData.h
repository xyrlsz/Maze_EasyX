#include <cstddef>
#include <vector>

#include"prim.h"
class MazeData {
public:
	
	MazeData() {
		this->cols = 0;
		this->rows = 0;
		this->start_r = 0;
		this->start_c = 0;
		this->end_r = 0;
		this->end_c = 0;
	}
	MazeData(int rows, int cols) {
		this->cols = cols;
		this->rows = rows;
		std::vector<std::vector<int>> maze(rows, std::vector<int>(cols, 0));
		this->maze = maze;
		this->start_r = 0;
		this->start_c = 0;
		this->end_r = rows - 1;
		this->end_c = cols - 1;
	}
	MazeData(int rows, int cols, int start_r,
		int start_c, int end_r, int end_c) {
		this->cols = cols;
		this->rows = rows;
		this->start_r = start_r;
		this->start_c = start_c;
		this->end_r = end_r;
		this->end_c = end_c;

	}
	MazeData(std::vector<std::vector<int>> maze) {
		this->maze = maze;
		this->cols = int(maze[0].size());
		this->rows = int(maze.size());
		this->start_r = 0;
		this->start_c = 0;
		this->end_r = rows - 1;
		this->end_c = cols - 1;
	}
	MazeData(std::vector<std::vector<int>> maze, int start_r,
		int start_c, int end_r, int end_c) {
		this->maze = maze;
		this->cols = int(maze[0].size());
		this->rows = int(maze.size());
		this->start_r = start_r;
		this->start_c = start_c;
		this->end_r = end_r;
		this->end_c = end_c;

	}
	int getRows() {
		return this->rows;
	}
	int getCols() {
		return this->cols;
	}
	std::vector<std::vector<int>> getMazeMatrix() {
		return this->maze;
	}
	std::pair<int, int> getStart() {
		return std::pair<int, int>(this->start_r, this->start_c);
	}
	std::pair<int, int> getEnd() {
		return std::pair<int, int>(this->end_r, this->end_c);
	}
private:
	/*int** maze;*/
	std::vector<std::vector<int>> maze;
	int rows;
	int cols;
	int start_r;
	int start_c;
	int end_r;
	int end_c;
protected:
	
};



