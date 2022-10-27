#include <iostream>
using namespace std;
/*
拷贝构造函数的调用时机
*/



class Person {
	int age;

public:
	Person() {
		cout << "Person的无参构造函数" << endl;
	};

	Person(int a) {
		age = a;
		cout << "Person的有参构造函数" << endl;
	};

	Person(const Person &p) {
		age = p.age;
		cout << "Person的copy构造函数" << endl;
	};

	~Person() {
		cout << "Person的析构函数" << endl;
	};
};

// 1.使用一个已经创建完毕的对象来初始化一个新对象
void test01() {
	Person p1;
	Person P2(p1);
};

// 2.值传递的方式给函数参数传值
void test02(Person p) {
	return;
};

// 3.值方式返回局部对象
Person test03() {
	Person p;
	return p;
};

int main() {
	cout << "**test01**" << endl;
	test01();

	cout << "**test02**" << endl;
	Person p1;
	test02(p1);
	
	cout << "**test03**" << endl;
	Person p2 = test03();
		
	return 0;
}
