#include <iostream>
using namespace std;
/*
表达式1 ？ 表达式2 ： 表达式3
	表达式1 -> true,  表达式2
	表达式1 -> false, 表达式3
三目运算符号最好用（）括起来。否则可能没用！
*/

int main() {
	int a,b,c;
	cout << "请输入a:";
	cin >> a;
	cout << "请输入b:";
	cin >> b;

	//取a,b的大者，赋值给c
	//a > b ? c = a : c = b;
	c = (a > b ? a : b);
	cout << "c的值为" << c << endl;

	//取a,b的大者，赋值为100
	(a > b ? a : b) = 100;
	cout << "a的值为" << a << endl;
	cout << "b的值为" << b << endl;
	return 0;
}
