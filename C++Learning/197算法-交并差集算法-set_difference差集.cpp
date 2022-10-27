#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
差集：
	set_difference(容器1起始迭代器，容器1结束迭代器，容器2起始迭代器，容器2结束迭代器，目标容器起始迭代器)
注意：容器1 - 容器2 的差集 和 容器2 - 容器1 的差集 是完全不同的。
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

	// 创建目标容器1 目标容器1 resize
	vector<int> targ1;
	targ1.resize(v1.size());
	cout << "V1 - V2 的差集" << endl;
	vector<int>::iterator itEnd1 = set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),targ1.begin());
	for_each(targ1.begin(), itEnd1, myPrint);
	cout << endl;

	// 创建目标容器2 目标容器2 resize
	vector<int> targ2;
	targ2.resize(v2.size());
	cout << "V2 - V1 的差集" << endl;
	vector<int>::iterator itEnd2 = set_difference(v2.begin(),v2.end(),v1.begin(),v1.end(),targ2.begin());
	for_each(targ2.begin(), itEnd2, myPrint);
	cout << endl;
	return 0;
}
