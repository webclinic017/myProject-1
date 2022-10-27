#include <iostream>
using namespace std;
/*
当使用动态多态时，父类指针指向子类对象。
这时，如果子类对象中有new出来的堆区数据，我们释放父类指针的时候就不能把子类堆区的数据释放掉，造成内存泄露。
*/
class Animal {
public:
	Animal()  {cout << "Animal的构造函数" << endl;};

	virtual void speak() = 0;

	// 1.实析构
	~Animal() {cout << "Animal的析构函数" << endl;};
	// 2.虚析构 可以解决父类指针释放时，子类中指针释放不干净的问题。
	// virtual ~Animal() {cout << "Animal的析构函数" << endl;};
	// 3.纯虚析构 有了纯虚析构，类就是抽象类
	// virtual ~Animal() = 0;
};
// 3.纯虚析构
// Animal::~Animal() {cout << "Animal的析构函数" << endl;}; // 析构函数比较特殊，不能只写纯虚函数，必须在类外加以实现。

class Cat : public Animal {
public:
	string * catName; // 指针
	Cat(string name)  {
		cout << "Cat的构造函数" << endl;
		catName = new string(name); // 数据开辟在堆区
	};

	~Cat() {
		cout << "Cat的析构函数" << endl;
		if (catName != NULL) {
			cout << "     delete Cat::catName" << endl;
			delete catName;
			catName = NULL;
		}
	};

	void speak() {
		cout << *catName << "小猫在说话" << endl;
	};
};



int main() {
	Animal * a = new Cat("Tom");
	a->speak();
	delete a; // 父类指针在析构时候不会调用子类的析构代码。
	
	return 0;
}
