#include <iostream>
using namespace std;
/*
在类中有些私有属性，如果需要被类外的其它类来访问，就需要“友元”技术
*/

class Building {
// 友元类声明
friend class Goodfriend;
private:
	string bedroom;
public:
	string livingroom;
	Building();
};
// 构造函数类外实现
Building::Building() {
	bedroom = "卧室";
	livingroom = "起居室";
};

class Goodfriend {
public:
	Building *building; // 成员属性：building类指针
	Goodfriend();
	void visit();
};
// 构造函数类外实现
Goodfriend::Goodfriend() {
	building = new Building;
};
// visit函数类外实现
void Goodfriend::visit() {
	cout << "好胖友正在访问 " << building->livingroom << endl;
	cout << "好胖友正在访问 " << building->bedroom << endl;
};

int main() {
	Goodfriend gdf;
	gdf.visit();

	return 0;
}
