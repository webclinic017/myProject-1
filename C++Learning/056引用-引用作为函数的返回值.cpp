#include <iostream>
using namespace std;
/*
注意：
	1.不要返回局部变量的引用
	2.函数的调用可以作为左值
*/

int & test01 () {
	int a = 10;
	return a; // warning: reference to local variable ‘a’ returned
};

int & test02 () {
	static int a = 10;
	return a;
};

int main() {
	// 1.不要返回局部变量的引用
	// int & res1 = test01(); // warning: reference to local variable ‘a’ returned
	// cout << res1 << endl; 

	// 2.函数的调用可以作为左值
	int & res2 = test02();
	cout << res2 << endl;
	cout << res2 << endl;

	test02() = 1000;
	cout << res2 << endl;
	cout << res2 << endl;
	
	return 0;
}
