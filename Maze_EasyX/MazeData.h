#include <cstddef>
#include <vector>

struct Cell;
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
	MazeData(uint32_t rows, uint32_t cols) {
		this->cols = cols;
		this->rows = rows;
		std::vector<std::vector<int>> maze(rows, std::vector<int>(cols, 0));
		this->maze = maze;
		this->start_r = 0;
		this->start_c = 0;
		this->end_r = rows - 1;
		this->end_c = cols - 1;
	}
	MazeData(uint32_t rows, uint32_t cols, uint32_t start_r,
		uint32_t start_c, uint32_t end_r, uint32_t end_c) {
		this->cols = cols;
		this->rows = rows;
		this->start_r = start_r;
		this->start_c = start_c;
		this->end_r = end_r;
		this->end_c = end_c;

	}
	MazeData(std::vector<std::vector<int>> maze) {
		this->maze = maze;
		this->cols = uint32_t(maze[0].size());
		this->rows = uint32_t(maze.size());
		this->start_r = 0;
		this->start_c = 0;
		this->end_r = rows - 1;
		this->end_c = cols - 1;
	}
	MazeData(std::vector<std::vector<int>> maze, uint32_t start_r,
		uint32_t start_c, uint32_t end_r, uint32_t end_c) {
		this->maze = maze;
		this->cols = uint32_t(maze[0].size());
		this->rows = uint32_t(maze.size());
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

private:
	/*int** maze;*/
	std::vector<std::vector<int>> maze;
	int rows;
	int cols;
	uint32_t start_r;
	uint32_t start_c;
	uint32_t end_r;
	uint32_t end_c;
};



