#include <iostream>
using namespace std;
/*
动态多态的条件：
	1.必须要有继承关系
	2.子类中必须重写父类的虚函数 (重写: 返回类型、函数名、参数列表必须一模一样！)
	3.父类的指针、引用 指向 子类的对象。
*/

class Animal {
public:
	// 为避免函数地址在编译阶段被绑定，我们用virtual关键字把父类中的函数变为"虚函数"。
	// 如此，这个函数地址就会在代码 运行阶段 根据需要进行绑定。
	virtual void speak() {
		cout << "动物在说话。" << endl;
	};
};

class Cat : public Animal {
public:
	void speak() {
		cout << "小猫在说话。" << endl;
	};
};

class Dog : public Animal {
public:
	void speak() {
		cout << "小狗在说话。" << endl;
	};
};
// 这里直接写Animal &a,函数的地址早绑定了，无论传入什么子类，它调用的都是绑定"父类"的函数。
void do_speak(Animal &a) // 动态多态：父类的指针式参数、引用式参数 传入 子类的对象。
{
	a.speak();
};

int main() {
	Animal a;
	Cat c;
	Dog d;
	do_speak(a);
	do_speak(c);
	do_speak(d);
	return 0;
}
