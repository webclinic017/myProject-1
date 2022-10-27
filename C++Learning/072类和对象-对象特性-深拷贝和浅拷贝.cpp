#include <iostream>
using namespace std;
/*
浅拷贝：简单的赋值拷贝操作
深拷贝：在内存的堆区重新申请空间，进行copy操作
*/

class Person {
public:
	int age;
	int * height;

	Person() {
		cout << "Person的无参构造函数" << endl;
	};

	Person(int a, int h) {
		age = a;
		height = new int(h); // 自己开辟一块内存，存放身高数据。返回指针给height。
		cout << "Person的有参构造函数" << endl;
	};

	// 自己写copy构造函数，来解决 自定内存 重复释放 的问题
	// 可以注释下面的copy构造函数来看区别
	Person(const Person &p) {
		age = p.age;
		// height = p.height; // 编译器默认copy构造函数的写法 								---- 浅拷贝
		height = new int( *p.height ); // 解引用->存放new开辟内存->返回内存地址给height		---- 深拷贝
	};

	~Person() {
		cout << "Person的析构函数" << endl;

		// 析构代码派上了用场!! 在析构代码中 把堆区new的数据做释放操作
		if (height != NULL) {
			delete height;
			height = NULL;
		};
	};
};

void test01() {
	Person p1(18, 160);
	cout << "p1.age = " << p1.age << "  p1.height = " << *p1.height << endl;
	Person p2(p1);
	cout << "p2.age = " << p2.age << "  p2.height = " << *p2.height << endl;
	return;
};

int main() {
	test01();
	return 0;
}
