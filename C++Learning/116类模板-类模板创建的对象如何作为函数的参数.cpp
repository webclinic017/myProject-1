#include <iostream>
using namespace std;
/*
通过类模板创建的对象，可以有三种方式向函数中进行传参。
*/
template<typename T1, typename T2>
class Person {
public:
	T1 name;
	T2 age;
	Person(T1 name, T2 age) {
		this->name = name; this->age = age;
	};
	void show() {
		cout << "姓名：" << this->name << "\t年龄：" << this->age << endl;
	};
};
// 传参方式：
// 1.指定参数类型: (最常用)
// 复制Person<string, int> p("张三", 19) --> Person<string, int> &p
void print1(Person<string, int> &p) {
	p.show();
};
// 2.将参数模板化：
template<typename S1, typename S2>
void print2(Person<S1, S2> &p) {
	p.show();
	cout << "参数S1的类型：" << typeid(S1).name() << endl;
	cout << "参数S2的类型：" << typeid(S2).name() << endl << endl;
};
// 3.直接将整个类模板化：
template<typename C>
void print3(C &p) {
	p.show();
	cout << "参数C的类型：" << typeid(C).name() << endl << endl;
};

int main() {
	Person<string, int> p("张三", 19);
	print1(p);
	print2(p);
	print3(p);
	return 0;
}
