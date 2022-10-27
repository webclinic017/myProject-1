#include <iostream>
using namespace std;
/*
用new开辟的内存空间会返回该内存空间的指针
int * p = new int(10);
*/

double * func1() {
	// 1.new的基本语法
	double * p = new double(10.0001);
	return p;
};

int * func2() {
	// 2.在利用new在堆区开辟内存空间，存放数组
	int * arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i+100;
	};
	return arr;

	 
};


int main() {
	// 1.测试一
	double * p = func1();
	cout << "func1: " << *p << endl;
	cout << "func1: " << *p << endl;
	// 释放：delete
	delete p;
	cout << "func1: " << *p << endl; // 内存已经被释放，已经是非法操作

	// 2.测试二
	int * q = func2();
	for (int i = 0; i < 10; i++) {
		cout << q[i] << endl;
	};
	// 释放：delete
	delete[] q; // 释放数组的时候需要加[]才可以。
	cout << "***********" << endl;
	for (int i = 0; i < 10; i++) {
		cout << q[i] << endl;
	};							// --> 乱码
	return 0;
}
