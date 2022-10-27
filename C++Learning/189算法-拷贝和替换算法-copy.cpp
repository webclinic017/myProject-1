#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
copy(原容器起始迭代器，原容器结束迭代器，目标容器起始迭代器)
*/
void myPrint(int num) {
	cout << num << " ";
};

int main() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	};

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(),v1.end(),v2.begin());
	cout << "v2：";
	for_each(v2.begin(),v2.end(),myPrint);
	cout << endl;
	return 0;
}
