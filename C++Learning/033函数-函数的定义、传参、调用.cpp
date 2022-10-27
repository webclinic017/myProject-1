#include <iostream>
using namespace std;
/*
返回的类型 函数名（参数列表）{
	函数语句；
	return表达式；
}
*/

// add()函数：两数相加
int add(int num1, int num2) {
	return num1 + num2;
}

// swap()函数：交换形参的值，不会影响到实参
void change(int num1, int num2) {
	cout << "交换前：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int tmp = num1;
	num1 = num2;
	num2 = tmp;

	cout << "交换后：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	return;
}

int main() {
	int tom = 19;
	int jerry = 1;
	
	// add()函数：两数相加
	cout << add(tom, jerry) << endl;

	// swap()函数：交换形参的值，不会影响到实参
	cout << "交换前：" << endl;
	cout << "tom = " << tom << endl;
	cout << "jerry = " << jerry << endl;
	change(tom,jerry);
	cout << "交换后：" << endl;
	cout << "tom = " << tom << endl;
	cout << "jerry = " << jerry << endl;
	return 0;
}
