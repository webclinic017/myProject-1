#include <iostream>
using namespace std;
/*
设置属性为私有；另开公有的方法对成员属性进行管理。
好处：
	1、可以自己控制属性的读写权限
	2、可以对写入属性的数据进行有效性控制
*/

class People {
private:
	// 1、可以自己控制属性的读写权限
	string	name = "张三";	 // 只读
	int		age  = 20;		// 可读 可写
	string	lover;			// 只写

public:
	string getName() {
		return name;
	};

	// 2、可以对写入属性的数据进行有效性控制
	void setAge(int a) {
		if ((a > 0) and (a < 150)) {
			age = a;
		}
		else {
			age = 0;
			cout << "年龄离谱！" << endl;
		};
	};

	int getAge() {
		return age;
	};

	void setLover(string l) {
		lover = l;
	};


};

int main() {
	People p1;
	cout << "name:" << p1.getName() << endl;
	p1.setAge(50);
	cout << "age:" << p1.getAge() << endl;
	p1.setLover("木老虎");

	return 0;
}
