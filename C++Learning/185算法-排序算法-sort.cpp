#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
/*

*/
void myPrint (int num) {
	cout << num << " ";
};

int main() {
	vector<int> v;
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);
	v.push_back(10);

	// 1.默认排序
	sort(v.begin(),v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	
	// 2.利用内建函数对象greater排序
	sort(v.begin(),v.end(),greater<int>());
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;
	return 0;
}
