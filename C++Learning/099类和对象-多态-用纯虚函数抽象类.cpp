#include <iostream>
using namespace std;
/*
纯虚函数语法： virtual 返回类型 函数名(参数表) = 0;
包含纯虚函数的类叫做抽象类，它无法实例化对象。
子类必须重写父类的所有纯虚函数，否则子类也成了抽象类，也同样无法实例化对象。
*/
class Father {
public:
	virtual void func() = 0;
};

class Son1 : public Father {
	// 子类必须重写父类的纯虚函数
};

class Son2 : public Father {
public:
	// 子类必须重写父类的纯虚函数
	void func() {
		cout << "Son2::func()" << endl;
	};
};

int main() {
	// Father f; // 不允许使用抽象类类型 "Father" 的对象:C/C++(322)
	// Son1 s1; // 不允许使用抽象类类型 "Son1" 的对象:C/C++(322)
	Son2 s2;
	s2.func();

	
	// Father * f = new Son1; // 不允许使用抽象类类型 "Son1" 的对象:C/C++(322)
	Father * f = new Son2;
	f->func();

	return 0;
}
