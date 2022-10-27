#include <iostream>
#include <unistd.h>
using namespace std;
/*
构造函数和析构函数：
	会被编译器自动调用。来完成对象的初始化工作。
构造函数：为属性赋值。
	类名() {}
析构函数：执行清理。
	~类名() {}
*/
class People {
public:
	People (string name, int age) {
		/* 1.构造函数
		没有返回值，不用写void
		函数名与类名相同
		可以有参数也可以发生重载
		在对象创建时自动调用一次 */
		cout << "我是People的构造函数" << endl;
	}

	~People () {
		/* 2.析构函数
		没有返回值 不写void
		函数名 = ~类名
		不可以有参数，不可以重载
		对象在销毁前会自动调用一次析构函数 */
		cout << "我是People析构函数" << endl;
	};
};



int main() {
	People p1("张三", 15);
	sleep(3);
	return 0;
}
