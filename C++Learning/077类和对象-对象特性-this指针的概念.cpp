#include <iostream>
using namespace std;
/*
this 指针。谁调用指向谁。
class A {this->age}; 这里的this指向a1
A a1; 
*/

class Person {
public:
	int age;
	// 1.用this解决形参和成员属性重名的问题
	Person(int age) {
		// age = age;
		this -> age = age;
	};
	// 普通
	void addOtherAge1 (Person &p) {
		age += p.age;
		return;
	};
	// 2.用return *this做返回值 用引用的方式接收，可以使函数完美地做到“进”、“出”一致
	Person& addOtherAge2 (Person &p) {
		this -> age += p.age;
		return *this;
	};
};


int main() {
	Person p1(18);
	cout << "p1.age = " << p1.age << endl;

	Person p2(10);
	Person p3(0);
	// 普通
	p3.addOtherAge1(p2);
	cout << "p3.age = " << p3.age << endl;
	// 链式编程思想
	p3.addOtherAge2(p2).addOtherAge2(p2).addOtherAge2(p2).addOtherAge2(p2).addOtherAge2(p2).addOtherAge2(p2).addOtherAge2(p2).addOtherAge2(p2);
	cout << "p3.age = " << p3.age << endl;
	
	return 0;
}
