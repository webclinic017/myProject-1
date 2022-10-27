#include <iostream>
using namespace std;
/*

*/

class Cube {
private:
	float high = 0.0;
	float width = 0.0;
	float length = 0.0;

public:
	void setHWL(float h, float w, float l) {
		if (h>0 and w>0 and l>0) {
			high = h;
			width = w;
			length = l;
		}
		else {
			high = width = length = 0;
			cout << "输入的长宽高不合法" << endl;
		};
	};

	float getHigh() {
		return high;
	};

	float getWidth() {
		return width;
	};

	float getLenth() {
		return length;
	};

	float calcArea() {
		return 2 * ((high * width) + (high * length) + (width * length));
	};

	float calcVolume() {
		return high * width * length;
	};

	bool isSameWith(Cube &c) {
		if (high == c.getHigh() and width == c.getWidth() and length == c.getLenth()) {
			return true;
		}
		else {
			return false;
		};
	};
};

bool isSame(Cube &c1, Cube &c2) {
	if (c1.getHigh() == c2.getHigh() and c1.getLenth() == c2.getLenth() and c1.getWidth() == c2.getWidth()) {
		return true;
	}
	else {
		return false;
	};
};

int main() {
	Cube c1;
	c1.setHWL(1,1,1);
	cout << "表面积: " << c1.calcArea() << endl;
	cout << "体积: " << c1.calcVolume() << endl;
	
	Cube c2;
	c2.setHWL(1,1.0,1);
	cout << "表面积: " << c2.calcArea() << endl;
	cout << "体积: " << c2.calcVolume() << endl;

	cout << "全局函数判断： " << isSame(c1, c2) << endl;
	cout << "成员函数判断： " << c1.isSameWith(c2) << endl;
	

	return 0;
}
