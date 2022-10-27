#include <iostream>
using namespace std;
/*
函数重载：函数名可以相同，提高复用性。
必要条件：
	1.同一个作用域下
	2.函数名称相同
	3.函数的 (参数类型 or 参数个数 or 参数顺序) 不同
注意：函数的返回值 不同，不是函数重载的条件
*/

void func(int a, int b) {
	cout << "调用func(int a, int b)" << endl;
};

void func(double a, int b) {
	cout << "调用func(double a, int b)" << endl;
};

void func(int b, double a) {
	cout << "调用func(int b, double a)" << endl;
};

void func(int b = 2) {
	cout << "调用func(int b = 2)" << endl;
};

/*
函数重载的注意事项：
	1.函数的参数是引用
	2.函数的参数有默认参数
*/

void func(string & a) {		   // 参数非只读
	cout << "调用func(string & a)" << endl;
};

void func(const string & a) {  // 参数只读
	cout << "调用func(const string & a)" << endl;
};

void func(int a, int b, int c) {
	cout << "调用func(int a, int b, int c)" << endl;
};

void func(int a, int b, int c, int d = 0) {
	cout << "调用func(int a, int b, int c, int d = 0)" << endl;
};
int main() {
	func(1);
	func(1.0,	1);
	func(1,		1);
	func(1,		1.0);

	string s = "abc";
	func(s);
	func("def");
	//func(1,1,1); // 当函数重载碰到默认值，很可能会发生二义性，要尽量避免这种情况。
	func(1,1,1,1);
	return 0;
}
