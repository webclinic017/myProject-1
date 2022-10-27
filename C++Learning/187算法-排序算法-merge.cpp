#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
merge(容器1起始迭代器，容器1结束迭代器，容器2起始迭代器，容器2结束迭代器，目标容器起始迭代器)
	可以将原来两个有序且升序的容器中的数据合并到一个新容器，且新容器也是升序的。
*/
void myPrint(int num) {
	cout << num << " ";
};

int main() {
	vector<int> v1; vector<int> v2; vector<int> v3;
	for (int i = 1; i <= 5; i++) {
		v1.push_back(2 * i);
		v2.push_back(3 * i);
	};
	cout << "v1:" << endl;
	for_each(v1.begin(),v1.end(),myPrint);
	cout << endl;
	cout << "v2:" << endl;
	for_each(v2.begin(),v2.end(),myPrint);
	cout << endl;

	// 合并
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	cout << "v3:" << endl;
	for_each(v3.begin(),v3.end(),myPrint);
	cout << endl;

	return 0;
}
