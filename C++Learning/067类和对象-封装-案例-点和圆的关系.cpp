#include <iostream>
using namespace std;
/*
一个点和一个圆，如何判断点在（圆上|圆外|圆内）
	设置坐标系 以(0,0)作为圆心
*/
class Circle {
public:
	float r = 0;
	Circle(float banjin) {
		r = banjin;
		cout << "圆的半径：" << r << endl;
	};

};

class Point {
public:
	float x;
	float y;

	Point(float x1, float y1):x(x1),y(y1){
		cout << "点的坐标(" << x << "," << y << ")" << endl;
	};

	bool isInCircle(Circle c) {
		bool res;
		c.r * c.r > x * x + y * y ? res = true : res = false;
		return res;
	};

	bool isOnCircle(Circle c) {
		bool res;
		c.r * c.r == x * x + y * y ? res = true : res = false;
		return res;
	};

	bool isOutCircle(Circle c) {
		bool res;
		c.r * c.r < x * x + y * y ? res = true : res = false;
		return res;
	};

};

int main() {
	class Point p(1.991,1.2);
	class Circle c(10.2);
	cout << p.isInCircle(c) << endl;
	cout << p.isOnCircle(c) << endl;
	cout << p.isOutCircle(c) << endl;
	return 0;
}
