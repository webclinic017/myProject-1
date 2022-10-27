#include <iostream>
using namespace std;
/*
常成员函数：数据类型 函数名() const {};
	不可以修改成员属性
	mutable修饰的成员属性依然可修改
常对象：const 类名 对象名;
	只能调用常成员函数
*/
class Person {
public:
	int age;
	mutable int score;
	Person() {};
	
	// 理解this指针的本质为指针常量 ===> Person * const this;
	// 		它只能修改值而不能修改指向
	// 当我们用const修饰成员函数时 ===> const Person * const this;
	// 		它连值都不可以修改了。
	void change1() const {
		// age = 18; // 不可修改普通成员属性的值
		score = 20;
	};
	void change2() {
		age = 18;
		score = 20;
	};
};
int main() {
	Person p1;
	p1.change1();
	p1.change2();
	p1.age+=1;
	p1.score+=1;
	cout << p1.age << endl;
	cout << p1.score << endl;
	
	// 常对象
	const Person p2;
	p2.change1();
	// p2.change2();	// 常对象只能调用常成员函数
	// p2.age+=1;		// 常对象不能修改普通的成员属性
	p2.score+=1;
	// cout << p2.age << endl;
	cout << p2.score << endl;



	
	return 0;
}
