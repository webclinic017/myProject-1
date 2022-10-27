#include <iostream>
using namespace std;
/*
区别：
	1.类模板不可进行自动类型推导
	2.在模板的参数列表中可以有默认参数
*/

template<typename NameType=string, typename AgeType=int>
class Person {
public:
	NameType name;
	AgeType age;
	Person(NameType n, AgeType a) {this->name = n; this->age = a;};
	void printSelf() {cout << this->name << endl; cout << this->age << endl;};
};

int main() {
	char name = 'F';
	double age = 18.245;
	Person<char,double> p(name, age); // 调用的时候要有模板参数列表<>
	p.printSelf();

	// 1.类模板不可进行自动类型推导
	// Person p1("张三",10); // error: missing template arguments before ‘p1’

	// 2.在模板的参数列表中可以有默认参数
	Person<> p2("张三",10);
	p2.printSelf();


	return 0;
}