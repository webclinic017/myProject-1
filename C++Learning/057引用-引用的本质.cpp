#include <iostream>
using namespace std;
/*
引用的本质就是：创建了一个名为ref的"指针常量"。
	当我们对引用进行赋值操作时，相当于对这个ref的指针常量进行解引用*ref。
	之所以引用初始化完成后不可再改变，正是由于它"指针常量"的本质。
*/

int main() {
	int a = 10;
	int & ref = a;			// ==> like int * const ref = &a;
	ref = 20;				// ==> like *ref = 20;
	ref = 100;				// ==> like *ref = 100;
	cout << ref << endl;	//like cout << *ref << endl;
	return 0;
}
