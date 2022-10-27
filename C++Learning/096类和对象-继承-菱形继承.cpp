#include <iostream>
using namespace std;
/*
虚继承、虚基类：
关键字：virtual
实际上子类继承的不是两份数据而是两份指针，这两个指针会通过自己的偏移量找到同一份数据。
*/
// 1.爷爷类：动物
class Animal {
public:
	int age; // 兽龄
};
// 2.爸爸类：马、驴 利用 virtual 关键字使父类虚继承爷类。
class Horse  : virtual public Animal {};
class Donkey : virtual public Animal {};
// 3.子类：骡
class Mule : public Horse , public Donkey {};

int main() {
	Mule m;
	// 虚继承之后我们两个父类继承得到的数据是同一份。
	m.Horse::age = 10;
	m.Donkey::age = 20;
	cout << "m.Horse::age = "  << m.Horse::age << endl;
	cout << "m.Donkey::age = " << m.Donkey::age << endl;
	cout << "m.age = "         << m.age << endl; // error: request for member ‘age’ is ambiguous
	

	return 0;
}
