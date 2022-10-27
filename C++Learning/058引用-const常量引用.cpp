#include <iostream>
using namespace std;
/*
如果担心 函数的引用传递参数 在函数体执行的过程中被某个代码误修改。我们可以加const，把它变为一个常量引用。
*/

void showValue(const int & val) {
	// val = 200; // 假如这是一个误操作，const修饰的常量引用 可以帮我们一下子看出来。
	cout << "val = " << val << endl;
};


int main() {
	int a = 10;
	// int & ref = 10; 				//wrong:  非常量引用的初始值必须为左值。引用 必须是合法的内存地址。
	const int & ref = 10;			//right:  ==> int tmp = 10; const int &ref = tmp;
	// ref = 20;					//wrong:  加了const之后现在ref处于只读状态，不可修改它的值。

	int b = 20;
	showValue(b);
	cout << "b = " << b << endl;
	
	return 0;
}
