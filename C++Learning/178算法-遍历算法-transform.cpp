#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
算法常用的头文件：
	algorithm、numeric、functional
tramsform(原容器起始迭代器、原容器结束迭代器、目标容器起始迭代器、回调函数或函数对象)
*/
// 打印功能
void myPrint(int num) {
	cout << num << " ";
};

int myRule(int num) {
	return num * 100;
};

int main() {
	vector<int> origin; // 原容器
	for (int i = 1; i <= 10; i++) 
		{origin.push_back(i);};
	for_each(origin.begin(), origin.end(), myPrint); // 打印
	cout << endl;

	vector<int> target; // 目标容器
	target.resize(origin.size()); // 重新指定大小
	transform(origin.begin(), origin.end(), target.begin(), myRule); // 搬运（自定规则）
	for_each(target.begin(), target.end(), myPrint); // 打印
	cout << endl;


	return 0;
}
