#include <iostream>
using namespace std;
/*
封装：
	将属性和行为糅合成一个整体来表现生活中的事物
	对属性和行为加以权限控制
语法：
	class 类名{访问权限:	属性 / 行为}
术语：
	成员：属性+行为
	成员属性：属性
	成员变量：属性
	成员函数：行为
	成员方法：行为
*/


// 设计一个“圆”类，求圆的周长
const float PI = 3.14159265;
class Circle {
	//访问权限
	public:

	// 属性 （半径）
	float r;

	// 行为 （计算圆的周长）
	float calculateZC() {
		return 2 * PI * r;
	};
};

class Student {
	public:

	string name;
	unsigned long number;

	void show() {
		cout << "姓名：" << name << endl;
		cout << "学号：" << number << endl;
	};
};

int main() {
	// 实例化
	Circle c1;
	c1.r = 5;
	cout << "圆半径:" << c1.r << " 圆周长:" << c1.calculateZC() << endl;

	Student s1;
	s1.name = "边边";
	s1.number = 3120112113;
	s1.show();
	
	return 0;
}
