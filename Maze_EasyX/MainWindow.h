#pragma once
#include <easyx.h>
class MainWindow {
public:
	MainWindow() {}
	void show() {
		COLORREF green = RGB(0, 255, 0);
		initgraph(1280, 720 | EX_DBLCLKS| EX_SHOWCONSOLE);

		//circle(200, 200, 100);	// ��Բ��Բ��(200, 200)���뾶 100
		solidrectangle(0, 0, 1280, 720);
		//setfillcolor(green);
		//solidrectangle(0, 0, 720, 720);
	}
};
