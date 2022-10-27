#include <iostream>
using namespace std;
/*
同名的静态函数类似非静态函数。多了一个类名式调用法。
*/
class Father {
public:
	static int age;
	static void func();
	static void func(int a);
};
int Father::age = 45;
void Father::func() 	 {cout << "父类func()函数调用" << endl;};
void Father::func(int a) {cout << "父类func(int a)函数调用" << endl;};

class Son : public Father {
public:
	static int age;
	static void func();
};
int Son::age = 16;
void Son::func() {cout << "子类func()函数调用" << endl;};

int main() {
	// 1.对象式调用
	Son s;
	cout << "对象式调用：" << endl;
	cout << "son's age = " << s.age << endl;
	cout << "father's age = " << s.Father::age << endl;
	s.func();
	s.Father::func();
	s.Father::func(5);

	// 2.函数式调用
	cout << endl << "函数式调用：" << endl;
	cout << "son's age = " << Son::age << endl;
	cout << "father's age = " << Son::Father::age << endl; // 第一个"::"表示用函数式调用; 第二个"::"表示Father作用域
	Son::func();
	Father::func();
	Father::func(5);
	return 0;
}
