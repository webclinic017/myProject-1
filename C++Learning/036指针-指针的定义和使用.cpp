#include <iostream>
using namespace std;
/*
指针的作用：可以用指针来保存一个16进制的内存地址，从而间接地访问这个内存地址
*/

int main() {
	int tom = 20;

	//1.定义指针 数据类型 * 指针变量命
	int * t;

	//2.让指针变量记录tom的地址
	t = &tom;
	cout << "tom的地址为："	 << &tom << endl;
	cout << "指针t = " 		<< t	<< endl;

	//3.使用指针 （*指针）可以解引用指针，找到指针指向地址的变量 (可读、可写)
	cout << "指针指向的变量为：" << *t << endl;
	*t = 100;
	cout << "*t=" << *t << ", 此时tom=" << tom << endl;
	
	return 0;
}
