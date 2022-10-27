#include <iostream>
using namespace std;
/*
1.普通函数可以发生隐式类型转换
2.函数模板 用自动类型推导, 不可以发生隐式类型转换
3.函数模板 用显示指定类型, 才可以发生隐式类型转换
*/

// 普通函数
int normalAdd(int a, int b) {
	return a+b;
};

// 函数模板
template<typename T>
T templateAdd(T a, T b) {
	return a+b;
};

int main() {
	int a = 1; int b = 2;
	char c = 'c'; char d = 'd';
	// 普通函数
	cout << normalAdd(a,c) << endl;
	cout << normalAdd(c,d) << endl;

	// 函数模板-自动类型推导
	// cout << templateAdd(a,c) << endl; // note:   deduced conflicting types for parameter ‘T’ (‘int’ and ‘char’)
	cout << templateAdd(c,d) << endl;
	// cout << templateAdd(1,2.1) << endl; // note:   deduced conflicting types for parameter ‘T’ (‘int’ and ‘double’)
	

	// 函数模板-显示指定类型
	cout << templateAdd<float>(a,c) << endl;
	cout << templateAdd<double>(c,d) << endl;
	cout << templateAdd<float>(1,2.1) << endl;



	
	
	
	return 0;
}
