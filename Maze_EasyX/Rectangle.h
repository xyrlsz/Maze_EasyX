#include <vector>
class Rectangle {
public:
	Rectangle() :left(0), top(0), right(0), bottom(0) {}
	Rectangle(int left, int top, int right, int bottom) :left(left), top(top), right(right), bottom(bottom) {}
	Rectangle(int top_left, int bottom_right, int size) :left(top_left), top(top_left + size),
		right(bottom_right), bottom(bottom_right + size) {}
	int getLeft() {
		return this->left;
	}
	int getTop() {
		return this->top;
	}
	int getRight() {
		return this->right;
	}
	int getBottom() {
		return this->bottom;
	}


private:
	int left;
	int top;
	int right;
	int bottom;
};