#include <iostream>
#include <unistd.h>
using namespace std;
/*

*/

class People {
	/* 1.构造函数
	有参构造，无参构造
	普通构造，拷贝构造 */
	
	string name;
	int age;

public:
	People () {
		cout << "我是People的(无参)构造函数" << endl;
	};

	People (string n, int a) {
		string name = n;
		int age = a;
		cout << "我是People的(普通、有参)构造函数" << endl;
	}
	
	People (const People &p) { // 将传入的人的所有属性做一个引用，再限制其不可更改，再将属性进行copy。
		string name = p.name;
		int age = p.age;
		cout << "我是People的(拷贝、有参)构造函数" << endl;
	}


	~People () {
		cout << "我是People析构函数" << endl;
	};
};



int main() {
	// 构造函数的构造方法
	// 1.括号法
	People p1;
	People p10(); // 这种写法不对，编译器会把它当作一个“函数声明”
	People p2("张三", 15);
	People p3(p2);
	cout << "括号法↑" << endl << endl << endl;
	
	// 2.显示法
	People p4;
	People p5 = People("张三", 15); // 等号右边叫做"匿名对象"，当前行结束后会马上销毁
	People p6 = People(p5);        // 等号右边叫做"匿名对象"，当前行结束后会马上销毁
	// 不要利用 "拷贝构造函数" 来初始化一个"匿名对象" 
	People(p5); // error: redeclaration of ‘People p5’| 原因：People(p5); 会被机器读成=====>> People p5;
	cout << "显示法↑" << endl << endl << endl;

	// 3.隐式法
	// People p4 = 15; // People p4 = 15; 会被机器读成=====>> People p4 = People(15);



};