#include <iostream>
using namespace std;
/*
引用：给变量起别名。
数据类型 &别名 = 原名
注意事项：
	引用必须初始化，且在初始化后不可发生改变
		int &b; 				错误 必须初始化完整
		int &b = a; int &b = c; 错误 初始化完成后不可再改变
*/

int main() {
	int a = 10; 
	int d = 30;

	int &b = a; // 创建引用
	b = 20;		// 利用别名

	cout << "a的地址： " << &a << endl;
	cout << "b的地址： " << &b << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// int &c; // error: ‘c’ declared as reference but not initialized
	// int &b = d; // error: redeclaration of ‘int& b’

	return 0;
}
