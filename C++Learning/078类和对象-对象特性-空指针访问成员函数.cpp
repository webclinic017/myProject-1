#include <iostream>
using namespace std;
/*
空指针也可访问成员函数。
	但要确保成员函数里没有用到this指针，否则报错！
*/
class Person {
public:
	int age;
	void showName() {
		cout << "我是Person::showName()" << endl;
	}
	void showAge() {
		if (this == NULL) {
			cout << "不允许调用Person::showAge(),指针为空" << endl;
		}
		else {
			cout << "我是Person::showAge()" << endl 
				 << "Person::age = " << age << endl;
				 // age ===> this->age：this指针不能为空，否则报错
		}
	}
};

int main() {
	Person * p = NULL;
	
	p->showName();
	p->showAge();
	cout << "p.age=" << p->age << endl; // 同理,用到了this指针
	return 0;
}
