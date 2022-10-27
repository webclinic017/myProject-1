#include <iostream>
using namespace std;
/*
模板不是万能的，它遇到我们自定义的数据类型可能会傻眼。
特殊重载 语法：
	template<> 返回类型 函数名(自定义数据类型参数) {}
*/
class Person {
public:
	string name; int age;
	Person(string name, int age) {
		this->name = name; this->age = age;
	};
};
template<typename T>
void myCompare(T &a, T &b) {
	if (a == b) {
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	};
};

// 对自定义数据类型的特殊处理：写个重载
template<> void myCompare(Person &a, Person &b) {
	if (a.name == b.name && a.age == b.age) {
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	};
};

int main() {
	int a = 10; int b = 10;
	myCompare(a, b);

	Person p1("张三",18); Person p2("张三",18);
	myCompare(p1, p2);
	
	return 0;
}
