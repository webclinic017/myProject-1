#include <iostream>
using namespace std;
#include <vector> // vector容器头文件
#include <algorithm> // 标准算法头文件
/*

*/

template<typename T> // 也可以不写模板直接写函数
void myPrint(T a) {
	cout << a << endl;
};

int main() {
	vector<int> v;
	v.push_back(1); // 尾插法 插入数据
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// 遍历方法一：
	cout << "遍历方法一：" << endl;
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	while (itBegin != itEnd) {
		cout << *itBegin++ << endl;
	};

	// 遍历方法二：
	cout << "遍历方法二：" << endl;
	for (vector<int>::iterator i = v.begin(); i < v.end(); i++) {
		cout << *i << endl;
	};

	// 遍历方法三：
	cout << "遍历方法三：" << endl;
	for_each(v.begin(),v.end(),myPrint<int>);
	
	return 0;
}
