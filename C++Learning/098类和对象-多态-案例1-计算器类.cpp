#include <iostream>
using namespace std;
/*
多态的优点：
	1.代码组织结构清晰
	2.可读性强
	3.利于前期和后期的扩展和维护
*/
class Calculator {
public:
	int a = 10; int b = 20;
	virtual double calculate() {
		return 0.0;
	};
};

class Plus : public Calculator {
public:
	double calculate() {
		return a + b;
	};
};

class Sub : public Calculator {
public:
	double calculate() {
		return a - b;
	};
};




int main() {
	Calculator * c = new Plus; // 父类的指针、引用 指向 子类的对象。
	c->a = 100; c->b = 100;
	cout << "a+b=" << c->calculate() << endl;
	delete c; // 手动释放堆区内存

	c = new Sub; // 父类的指针、引用 指向 子类的对象。
	c->a = 100; c->b = 100;
	cout << "a-b=" << c->calculate() << endl;
	delete c; // 手动释放堆区内存

	return 0;
}
