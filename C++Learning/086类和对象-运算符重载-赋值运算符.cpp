#include <iostream>
using namespace std;
/*
首先明确：class类在创建的时候，编译器会默认提供4个函数（无参构造函数，有参构造函数，拷贝构造函数，
	““赋值运算函数””）
*/
class Person {
public:

	int * age;

	Person(int age) {
		this->age = new int(age);
	};
	
	// 自定义赋值运算
	Person& operator=(Person &p) {
		// 1.先置空原指针
		if (this->age != NULL) {
			delete age;
			this->age = NULL;
		}

		// 2.重开内存，深度拷贝
		this->age = new int(*p.age);

		// 3.返回自身，链式编程
		return *this;
		
	};

	~Person() {
		delete age;
	};
};

int main() {
	Person p1(18);
	Person p2(20);
	Person p3(30);
	// 当使用编译器默认的“operator=”函数时，使用的是浅拷贝，复制的是new的内存地址，当析构函数释放的时候，会导致重复释放。
	p2 = p1; 
	p1 = p2 = p3;
	cout << "p1.age = " << *p1.age << endl;
	cout << "p2.age = " << *p2.age << endl;
	cout << "p3.age = " << *p3.age << endl;
	return 0;
}
