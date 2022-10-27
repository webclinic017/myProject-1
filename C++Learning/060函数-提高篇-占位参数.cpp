#include <iostream>
using namespace std;

// 占位参数，第二个参数是占位参数。目前函数里用不到。
// 占位符参数一般⽤用于程序扩展和对C代码的兼容

void func1(int a, int) {
	cout << a << endl;
};

// 占位参数也可以有默认值
void func2(int a = 100, int = 100) {
	cout << a << endl;
};

int main() {
	func1(10,20);
	func2();
	return 0;
}
