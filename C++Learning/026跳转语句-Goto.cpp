#include <iostream>
using namespace std;
/*
飞雷神：先标记，再goto。
标记 大写+冒号 FLAG1:
*/

int main() {
	cout << "one" << endl;
	goto FLAG1;				// GOTO
	cout << "two" << endl;
	cout << "three" << endl;
	cout << "four" << endl;
	FLAG1:					// 标记
	cout << "five" << endl;
	return 0;
}
