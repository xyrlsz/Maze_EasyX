#include<iostream>
#include <graphics.h>
#include <conio.h>
#include<string>
#include<vector>
#include"Maze.h"
#include"MainWindow.h"

class MazeData;


int main() {
	MainWindow* mainWindow = new MainWindow();
	mainWindow->show();
	int mazeData[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
	{1, 1, 1, 0, 1, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	//int** convertedData = new int* [10];
	//for (int i = 0; i < 10; ++i) {
	//	convertedData[i] = new int[10];
	//	for (int j = 0; j < 10; ++j) {
	//		convertedData[i][j] = mazeData[i][j];
	//	}
	//}
	std::vector<std::vector<int>>convertedData(10, std::vector<int>(10, 0));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			convertedData[i][j] = mazeData[i][j];
		}
	}


	MazeData* mazeDataObject = new MazeData(convertedData);
	Maze* maze = new Maze(0, 0, 720, 720, mazeDataObject);
	/*drawMaze(maze, BLACK, WHITE);*/
	maze->draw(BLACK, WHITE);
	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}