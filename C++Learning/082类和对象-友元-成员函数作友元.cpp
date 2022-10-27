#include <iostream>
using namespace std;
/*
在类中有些私有属性，如果需要被类外的其它成员函数来访问，就需要“友元”技术
*/
class Building;

class Goodfriend {
public:
	Building * building; // 前面必须声明一个Building类
	Goodfriend();
	void visit1(); // 可以访问两个房间
	void visit2(); // 可以访问起居室
};

class Building {
friend void Goodfriend::visit1(); // 这里应为拿了Goodfriend的成员函数作友元，Goodfriend必须写在前。
private:
	string bedroom;
public:
	string livingroom;
	Building();
};

// 类外实现
Building:: Building() {
	this -> bedroom = "卧室";
	this -> livingroom = "起居室";
};
Goodfriend::Goodfriend() {
	this -> building = new Building;
};
void Goodfriend::visit1() {
	cout << "好胖友正在访问 " << building->livingroom << endl;
	cout << "好胖友正在访问 " << building->bedroom << endl;
};
void Goodfriend::visit2() {
	cout << "好胖友正在访问 " << building->livingroom << endl;
	// cout << "好胖友正在访问 " << building->bedroom << endl;
};

int main() {
	Goodfriend gdf;
	gdf.visit1();
	gdf.visit2();
	
	return 0;
}
