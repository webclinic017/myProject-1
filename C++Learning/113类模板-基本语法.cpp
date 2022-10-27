#include <iostream>
using namespace std;
/*
template<typename T>
class 类名 {.
	.....
}
*/

template<typename NameType, typename AgeType>
class Person {
public:
	NameType name; // 内置的参数用模板参数类型替代
	AgeType age;   // 内置的参数用模板参数类型替代
	Person(NameType n, AgeType a) {
		this->name = n;
		this->age = a;
	};
	void printSelf() {
		cout << this->name << endl;
		cout << this->age << endl;
	};
};

int main() {
	char name = 'F';
	double age = 18.245;
	Person<char,double> p(name, age); // 调用的时候要有模板参数列表<>
	p.printSelf();

	return 0;
}
