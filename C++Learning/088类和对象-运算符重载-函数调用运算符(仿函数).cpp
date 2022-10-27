#include <iostream>
using namespace std;
/*
函数调用运算符 ”(“ ”)“
也称为 ”仿函数“
仿函数的写法非常灵活
*/
class Mine {
public:
	void operator()(string s) {
		cout << "打印：" << s << endl;
	};

	int operator()(int a, int b) {
		return a+b;
	};
};

int main() {
	Mine m1;
	m1("good game!");
	int res = m1(42,58);
	cout << "res = " << res << endl;

	// 匿名对象调仿函数
	Mine()("哈哈哈");
	cout << "res = " << Mine()(100,100) << endl;
	return 0;
}
