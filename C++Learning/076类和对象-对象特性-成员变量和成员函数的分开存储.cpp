#include <iostream>
using namespace std;
/*
只有非静态成员变量 才存储在类的内存中，其他都在类外的内存中。
成员函数 无论静态还是非静态 都存在类外的内存中。
*/
class Person1{};					// 也会占用一个字节，为了跟其他类做区分
class Person2{int age;};			// 非静态成员变量 -- 在类内的空间存储
class Person3{static int age;};		// 静态成员变量
class Person4{void show();};		// 非静态成员函数
class Person5{static void show();};	// 静态成员函数

int main() {
	Person1 p1; Person2 p2; Person3 p3; Person4 p4; Person5 p5;
	cout << sizeof(p1) << endl;
	cout << sizeof(p2) << endl;
	cout << sizeof(p3) << endl;
	cout << sizeof(p4) << endl;
	cout << sizeof(p5) << endl;
	return 0;
}
