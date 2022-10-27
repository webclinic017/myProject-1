#include <iostream>
using namespace std;
/*

*/
class Father {
public:
	int a;
protected:
	int b;
private:
	int c;
};

// 公共继承
class Son1 : public Father {
public:
	void func() {
		a = 10; // 父类的公共属性 -> 子类的公共属性
		b = 20; // 父类的保护属性 -> 子类的保护属性
		// c = 30; // 父类的私有属性 无法继承
	};
};

// 保护继承
class Son2 : protected Father {
public:
	void func() {
		a = 10; // 父类的公共属性 -> 子类的保护属性
		b = 20; // 父类的保护属性 -> 子类的保护属性
		// c = 30; // 父类的私有属性 无法继承
	};
};

// 私有继承
class Son3 : private Father {
public:
	void func() {
		a = 10; // 父类的公共属性 -> 子类的私有属性
		b = 20; // 父类的保护属性 -> 子类的私有属性
		// c = 30; // 父类的私有属性 无法继承
	};
};

int main() {
	Son1 s1;
	s1.a = 10;
	// s1.b = 20; // 保护属性类外不可访问

	Son2 s2;
	// s2.a = 10; // 保护属性类外不可访问
	// s2.b = 20; // 保护属性类外不可访问

	Son3 s3;
	// s2.a = 10; // 私有属性类外不可访问
	// s2.b = 20; // 私有属性类外不可访问
	return 0;
}
