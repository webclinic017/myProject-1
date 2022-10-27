#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
/*
所谓内建的函数对象，就是c++已经帮我们提供好的各种各样的operator()仿函数。
需包含头文件<functional>
	template<typename T> bool logical_and<T>()	逻辑与
	template<typename T> bool logical_or<T>()	逻辑或
	template<typename T> bool logical_not<T>()	逻辑非
*/
void printVector(const vector<bool> &v) {
	for (vector<bool>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}; cout << endl;
};

int main() {
	// template<typename T> bool logical_not<T>()	逻辑非
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(true);
	printVector(v1);

	vector<bool> v2;
	v2.resize(v1.size());
	// transform标准算法algorithm参数请仔细看例子。第四个参数为谓词对象，这里用逻辑仿函数logical_not替代
	transform(v1.begin(),v1.end(),v2.begin(),logical_not<bool>());
	printVector(v2);	
	
	return 0;
}
