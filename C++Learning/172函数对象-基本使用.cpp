#include <iostream>
using namespace std;
/*
函数对象：
	就是某一个类的对象（实例）; 这个实例所在的类中 重载了operator() 运算符。
函数对象的使用：
	1.函数对象在使用的时候，可以像普通函数一样有参数和返回值
	2.函数对象比普通函数强，它内部可以有自己独有的状态（比如成员属性）
	3.函数对象可以做为参数传递
*/

// 1.函数对象在使用的时候，可以像普通函数一样有参数和返回值
class MyAdd {
public:
	int operator()(int num1, int num2) {
		return num1+num2;
	};
};
void test1() {
	MyAdd ma;
	cout << "3 + 5 = " << ma(3,5) << endl;
};


// 2.函数对象比普通函数强，它内部可以有自己独有的状态（比如成员属性）
class MyPrint {
public:
	int count; // 记录打印次数
	MyPrint() {
		this->count = 0;
	};
	void operator()(string words) {
		cout << words << endl;
		this->count++;
	};
};
void test2() {
	MyPrint mp;
	mp("哈哈");
	mp("c++");
	mp("快学完了");
	mp("^-^");
	cout << "打印次数" << mp.count << endl;
};


// 3.函数对象可以做为参数传递
void funcPrint(MyPrint &mp, string m_str) {
	mp(m_str);
};
void test3() {
	MyPrint mp;
	funcPrint(mp,"hello啊c++");
};


int main() {
	test1();
	test2();
	test3();
	return 0;
}
