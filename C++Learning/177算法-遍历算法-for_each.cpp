#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
算法常用的头文件：
	algorithm、numeric、functional
for_each(起始迭代器、末尾迭代器、函数名)
*/

// 1.普通函数
void printFunc(int num) {
	cout << num << " ";
};

// 2.仿函数
class myRule {
public:
	void operator()(int num) {
		cout << num << " ";
	};
};


int main() {
	vector<int> v;
	for (int i = 1; i <= 10; i++) {
		v.push_back(i);
	};
	// 1.普通函数 作 回调函数
	for_each(v.begin(), v.end(), printFunc);
	cout << endl;
	// 2.仿函数 作 回调函数
	for_each(v.begin(), v.end(), myRule()); // 使用仿函数做回调函数时，需要传入匿名对象
	cout << endl;

	return 0;
}
