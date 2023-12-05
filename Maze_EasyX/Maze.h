#pragma once
#include "Rectangle.h"
#include"MazeData.h"
#include <graphics.h>
#include <conio.h>
#include <queue>
#include <windows.h>
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
	void drawPath(std::queue<std::pair<int,int>> q) {
		int mazeRows = this->getRows();
		int mazeCols = this->getCols();
		int x = this->getLeft();
		int y = this->getTop();
		COLORREF color = GREEN;
		std::vector<std::vector<bool>> hash(mazeRows, std::vector<bool>(mazeCols, false));
		while (!q.empty()) {
			std::pair<int, int> coordinate = q.front();
			//if (hash[coordinate.first][coordinate.second] == false) {
			//	color = GREEN;
			//	hash[coordinate.first][coordinate.second] = true;
			//}
			//else
			//{
			//	color = WHITE;
			//	hash[coordinate.first][coordinate.second] = false;
			//}
			setfillcolor(color);
			solidrectangle(x + coordinate.second * cellSize, y + coordinate.first * cellSize, x + (coordinate.second + 1) * cellSize, y + (coordinate.first + 1) * cellSize);
			q.pop();
			Sleep(500);
		}

		
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
				if (this->getMazeData()->getMazeMatrix()[i][j] == 0) {
					setfillcolor(wall);
					solidrectangle(x + j * cellSize, y + i * cellSize, x + (j + 1) * cellSize, y + (i + 1) * cellSize);
				}
				// 画通道
				else {
					setfillcolor(path);
					solidrectangle(x + j * cellSize, y + i * cellSize, x + (j + 1) * cellSize, y + (i + 1) * cellSize);
				}
			}
			/*Sleep(200);*/

		}


	}
private:
	MazeData* mazeData;
	int cellSize;
};

//