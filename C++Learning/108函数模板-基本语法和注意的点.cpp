#include <iostream>
using namespace std;
/*
模板：
声明语法： 
	template<typename xx>
	返回值 函数名(参数) {
		代码实现
	}
*/

template<typename Te> // 声明一个模板，告诉编译器T是个通用的数据类型，不要对它报错。

// 坑：swap函数被系统用了，以后起名尽量起个性点的
void myswap(Te &a, Te &b) {
	Te tmp = a;
	a = b;
	b = tmp;
	cout << "A = " << a << endl;
	cout << "B = " << b << endl << endl;
}

// 注意2：模板不能直接使用，必须让编译器知道模板有个明确的数据类型才可以。
template<typename Te2>
void func() {
	cout << "func()函数" << endl;
}

int main() {
	int a1 = 1;			int b1 = 2;
	double a2 = 1.1;	double b2 = 2.2;
	float a3 = 1.11;	float b3 = 2.22;
	string a4 = "aaa";	string b4 = "bbb";
	// 传参方法：
	// 1.编译器自动推导
	myswap(a1,b1);
	myswap(a2,b2);
	// 2.显式指定类型
	myswap<float>(a3,b3);
	myswap<string>(a4,b4);

	//注意1：编译器自动推导必须推导出相同的数据类型才行。
	// myswap(a1,b2); // note:   deduced conflicting types for parameter ‘Te’ (‘int’ and ‘double’)
	
	// 注意2：模板不能直接使用，必须让编译器知道模板有个明确的数据类型才可以。
	// func(); // note:   couldn’t deduce template parameter ‘Te2’
	func<int>(); // 随便指明一个数据类型就没问题了；

	return 0;
}
