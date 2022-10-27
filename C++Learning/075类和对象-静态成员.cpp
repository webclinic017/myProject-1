#include <iostream>
using namespace std;
/*
static
	1 所有成员都共享同一份数据
	2 编译阶段就分配内存
	3 类内声明 类外初始化
*/

class Person {
// 一、类内声明
public:
	// 1 所有成员都共享同一份数据
	// 2 编译阶段就分配内存
	// 3 类内声明 类外初始化
	static int age;
	// 1 所有成员都共享同一份数据
	// 2 静态成员函数只能访问静态成员变量
	static void show();

	int height; // 非静态成员变量

private:
	static int score; // 私有静态成员变量
	static void show2(); // 私有静态成员函数
};

// 二、类外初始化
int Person::age = 100;
void Person::show() {
	cout << "我是Person::show()函数" << endl;
	age = 10;
	// height = 20; // 静态成员函数只能访问静态成员变量
};

// int Person::score = 100; // 私有静态成员变量访问不到
void Person::show2(){}; // 私有静态成员函数访问不到



int main() {
	Person p1;
	cout << "p1.age=" << p1.age << endl;
	Person p2;
	p2.age = 200;
	cout << "p1.age=" << p1.age << endl;

	// 访问方式:
	cout << "对象式：" << p1.age << endl;
	cout << "类名式：" << Person::age << endl;
	cout << "对象式：" << endl; p1.show();
	cout << "类名式：" << endl; Person::show();
	// Person::show2(); // 私有静态成员函数访问不到
	return 0;
}
