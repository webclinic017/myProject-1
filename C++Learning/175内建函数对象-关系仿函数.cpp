#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
/*
所谓内建的函数对象，就是c++已经帮我们提供好的各种各样的operator()仿函数。
需包含头文件<functional>
	template<typename T> bool equal_to<T>()		等于
	template<typename T> bool not_equal_to<T>()	不等于
	template<typename T> bool greater<T>()		大于
	template<typename T> bool greater_equal<T>()大于等于
	template<typename T> bool less<T>()			小于
	template<typename T> bool less_equal<T>()	小于等于
*/
void printVector(const vector<int> &v) {
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}; cout << endl;
};

int main() {
	// template<typename T> bool greater<T>() 大于
	vector<int> v;
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);
	v.push_back(10);
	v.push_back(30);
	printVector(v);

	sort(v.begin(),v.end());
	printVector(v);

	sort(v.begin(),v.end(),greater<int>()); // 这里谓词用关系仿函数
	printVector(v);

	return 0;
}
