#include <iostream>
using namespace std;
/*
class A {};
class B {
	public:
	class A a;
};
*/
class Phone {
public:
	string brand;

	Phone(string b) {
		brand = b;
		cout << "Phone的构造函数" << endl;
	};

	~Phone() {
		cout << "Phone的析构函数" << endl;
	};
};

class Person {
public:
	string name;
	class Phone phone;
	/*
		             	隐式法				显示法	（匿名构造函数）
	phone(p) ==> Phone phone = p ==> Phone phone = Phone(15)
	*/
	Person(string n, string p):name(n),phone(p) {
		name = n;
		phone.brand = p;
		cout << "Person的构造函数" << endl;
	};

	~Person() {
		cout << "Person的析构函数" << endl;
	};
};

int main() {
	// 会先构造Phone对象，再构造Person; 先析构Person，再析构Phone。
	Person p("张三", "sumsang");
	cout << p.name << "拿着" << p.phone.brand << "手机" << endl;
	return 0;
}
