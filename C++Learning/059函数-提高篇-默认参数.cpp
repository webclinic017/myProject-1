#include <iostream>
using namespace std;

// 1.无默认值的形参 必须在有默认值的实参之前
void func1(int a, int b = 10, int c = 20) {
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
};

// 2.函数声明有默认参数，函数的定义就不能有默认参数。
void func2(int a, int b = 50);

// void func2(int a, int b = 50) {cout << "func2()调用" << endl;}; // wrong: previous specification in ‘void func2(int, int)’ here
void func2(int a, int b) {cout << "func2()调用" << endl;}; // 只能这样


int main() {
	func1(-10);
	func2(-10);
	return 0;
}