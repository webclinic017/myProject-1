#include <iostream>
using namespace std;
/*
1.当子类和父类出现了 同名的成员 时，如果要调用父类的成员必须加作用域
2.父类中有多个与子类重名的函数 - 
	父类: func(), func(int), func(double)
	子类: func()
用子类对象调用时，即使是父类的有参函数func(int)，也不能直接调用，它被子类的func()隐藏了。必须加作用域
	
*/
class Father {
public:
	int age = 45;
	void func() {
		cout << "父类-func()调用" << endl;
	};
	
	void func(int) {
		cout << "父类-func(int)调用" << endl;
	};
};

class Son : public Father {
public:
	int age = 18;
	void func() {
		cout << "子类-func()调用" << endl;
	};
};

int main() {
	Son s;
	cout << "子类-年龄：" << s.age << endl;
	cout << "父类-年龄：" << s.Father::age << endl; // 调用父类的成员必须加作用域
	s.func();
	s.Father::func();	// 调用父类的成员必须加作用域
	// s.func(5);		// 即使是父类的有参函数func(int)，也不能直接调用，它被子类的func()隐藏了。必须加作用域
	s.Father::func(5);	// 即使是父类的有参函数func(int)，也不能直接调用，它被子类的func()隐藏了。必须加作用域
	return 0;
}
