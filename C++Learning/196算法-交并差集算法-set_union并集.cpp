#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
并集：
	set_union(容器1起始迭代器，容器1结束迭代器，容器2起始迭代器，容器2结束迭代器，目标容器起始迭代器)
*/
void myPrint(int num) {
	cout << num << " ";
};

int main() {
	vector<int> v1;
	vector<int> v2;
	for (int i=1; i<=10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	};

	cout << "v1:" << endl;
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
	cout << "v2:" << endl;
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;

	// 创建目标容器
	vector<int> targ;
	// 目标容器resize
	targ.resize(v1.size()+v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),targ.begin());
	cout << "targ:" << endl;
	for_each(targ.begin(), itEnd, myPrint);
	cout << endl;

	return 0;
}
