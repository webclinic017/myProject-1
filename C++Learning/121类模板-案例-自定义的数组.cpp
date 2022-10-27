#include "121MyArray.hpp"
#include <iostream>
using namespace std;
/*

*/

int main() {
	myArr<int> a(0);
	a.insert(1); // 测试尾插
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.showArr(); // 测试打印
	myArr<int> b(a); // 测试copy构造
	b.showArr();
	myArr<int> c(100); 
	c = a; // 测试operator=
	c.showArr();
	a.findByIdx(3); // 测试访问
	a.backspace(); // 测试尾删
	a.showArr();
	a.getCapacity();
	myArr<int> d(0);
	b.getSize();



	// a.func();
	// a.insert(44);
	// a.backspace();
	// a.backspace();
	// a.showArr();
	// a.findByIdx(3);
	// myArr<int> b = a;
	// b.showArr();
	
	return 0;
}
