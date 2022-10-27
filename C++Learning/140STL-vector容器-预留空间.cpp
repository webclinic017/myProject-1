#include <iostream>
using namespace std;
#include <vector>
/*
v.reserve(1e7); 一开始就知道会有多少个数据在vector中。我们直接指定它的capacity为1e7
*/

int main() {
	vector<int> v;
	// v.reserve(1e7); // 注释这行代码查看不同结果。
	int * p = NULL;
	int count = 0;
	for (int i = 1; i <= 1e7; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			count++;
		};
	};
	cout << "vector添加数据过程中重新开辟内存空间的次数为：" << count << endl;
	return 0;
}
