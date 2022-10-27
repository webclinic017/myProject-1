#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>
/*
用于后期重新填充
	fill(起始迭代器，结束迭代器，新值)
*/
void myPrint(int num) {
	cout << num << " ";
};

int main() {
	vector<int> v;
	for (int i=1; i<=10; i++) {
		v.push_back(i);
	};
	cout << "原来：" << endl;
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;

	cout << "重新填充后：" << endl;
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;
	return 0;
}
