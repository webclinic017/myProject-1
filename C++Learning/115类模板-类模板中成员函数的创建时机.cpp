#include <iostream>
using namespace std;
/*
类模板中的成员函数在调用时才会去创建。
*/
// 普通类
class Person1 {
public:
	void showPerson1() {
		cout << "show class Person1" << endl;
	}
};
// 普通类
class Person2 {
public:
	void showPerson2() {
		cout << "show class Person2" << endl;
	}
};
// 类模板
template<typename tempType>
class TemplateClass {
public:
	tempType t;
	void show1() {
		t.showPerson1(); // 在调用这个函数之前是不会报错的。
	};
	void show2() {
		t.showPerson2(); // 在调用这个函数之前是不会报错的。
	};
};

int main() {
	TemplateClass<Person1> T1; // 当我们显示指定模板参数为Person1时
	T1.show1();				   // 我们只能用show1(),因为Person1没有showPerson2()成员函数。

	TemplateClass<Person2> T2;
	T2.show2();

	return 0;
}
