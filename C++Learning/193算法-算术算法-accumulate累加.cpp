#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
/*
累加算法：
	accumulate(起始迭代器，结束迭代器，累加初始值)
*/

int main() {
	vector<int> v;
	for (int i = 1; i <= 100; i++) {
		v.push_back(i);
	};
	int total = accumulate(v.begin(),v.end(),1e6);
	cout << "total + 100000 = " << total << endl;
	return 0;
}
