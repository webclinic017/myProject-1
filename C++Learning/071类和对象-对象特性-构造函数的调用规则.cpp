#include <iostream>
using namespace std;
/*
代码有有参构造，c++不提供无参构造，只提供默认拷贝构造。
代码有拷贝构造，c++不提供其他构造。
*/

class Person {

public:
	int age;
	
	/*
	Person() {
		cout << "Person的无参构造函数" << endl;
	};
	*/

	Person(int a) {
		age = a;
		cout << "Person的有参构造函数" << endl;
	};

	// 即使我们把拷贝构造注视掉，c++也会提供默认的copy构造函数
	/*
	Person(const Person &p) {
		age = p.age;
		cout << "Person的copy构造函数" << endl;
	};
	*/

	~Person() {
		cout << "Person的析构函数" << endl;
	};
};

int main() {
	// Person p0; // error: 类 "Person" 不存在默认构造函数C/C++(291)
	Person p1(18);
	Person p2(p1);
	cout << "p2的年龄为：" << p2.age << endl;
	
	return 0;
}
