#pragma once
#include "Rectangle.h"
#include"MazeData.h"
#include <graphics.h>
#include <conio.h>

class Maze : public Rectangle {
public:
	Maze() {
		Rectangle::Rectangle();
		this->mazeData = new MazeData();
		this->cellSize = 0;
	}
	Maze(int left, int top, int right, int bottom, MazeData* maze) {
		Rectangle::Rectangle(left, top, right, bottom);
		this->mazeData = maze;
		int size1 = (right - left) / this->getCols();
		int size2 = (bottom - top) / this->getRows();
		this->cellSize = size1 < size1 ? size1 : size2;
	}
	MazeData* getMazeData() {
		return this->mazeData;
	}
	int getRows() {
		return this->mazeData->getRows();
	}
	int getCols() {
		return this->mazeData->getCols();
	}
	int getCellSize() {
		return this->cellSize;
	}

	void draw(COLORREF wall, COLORREF path) {
		int mazeRows = this->getRows();
		int mazeCols = this->getCols();
		int x = this->getLeft();
		int y = this->getTop();
		//先画一个背景
		//setfillcolor(path);
		//solidrectangle(this->getLeft(), this->getTop(), this->getRight(), this->getBottom());

		int cellSize = this->getCellSize();
		for (int i = 0; i < mazeRows; ++i) {
			for (int j = 0; j < mazeCols; ++j) {
				// 画墙
				if (this->getMazeData()->getMazeMatrix()[i][j] == 1) {
					setfillcolor(wall);
					solidrectangle(x + j * cellSize, y + i * cellSize, x + (j + 1) * cellSize, y + (i + 1) * cellSize);
				}
				// 画通道
				else {
					setfillcolor(path);
					solidrectangle(x + j * cellSize, y + i * cellSize, x + (j + 1) * cellSize, y + (i + 1) * cellSize);
				}
			}
		}


	}
private:
	MazeData* mazeData;
	int cellSize;
};

//