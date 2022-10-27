#include <iostream>
using namespace std;
/*
利用对组可以返回两个数据（试过了，不能是三个，只能是两个）
*/

pair<bool,int> myCompare(int a, int b) {
	if (a > b) {
		return make_pair(false, a-b); // 创建方式一
	}
	else if (a < b) {
		return make_pair(false, b-a);
	}
	else {
		pair<bool,int> tmp_value(true, 0); // 创建方式二
		return tmp_value;
	};
};


int main() {
	pair<bool,int> p;
	p = myCompare(5,3);
	cout << "p.first = " << p.first << endl;
	cout << "p.second = " << p.second << endl;
	return 0;
}
