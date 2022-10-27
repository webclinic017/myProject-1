#include <iostream>
using namespace std;
/*
左移运算符 配合 友元可以实现： 输出自定义数据类型
*/
class Person {

friend ostream & operator<<(ostream &cout, Person &p);

private:
	int a;
	int b;
public:
	Person(int a, int b) {
		this->a = a;
		this->b = b;
	};

	// 如果这样写的话 最后调用 “p1 << cout” 显然是不对的，也无法完成链式编程
	void operator<<(ostream &cout) {
		cout << "a = " << this->a << ", b = " << this->b << endl;
	};

};

// 所以得用全局函数，输入ostream &cout 和 Person &p ，返回值为 ostream &，也可以实现链式编程。
ostream & operator<<(ostream &cout, Person &p) {
	cout << "a = " << p.a << ", b = " << p.b << " | ";
	return cout;
};


int main() {
	Person p1(10,20);
	Person p2(30,40);
	
	p1 << cout;
	cout << endl;
	cout << p1 << p2 << endl;
	return 0;
}