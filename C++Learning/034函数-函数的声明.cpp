#include <iostream>
using namespace std;
/*
格式： 
	返回的类型 函数名（参数列表）;

所谓函数的声明：就是在函数的定义前，先告诉编译器有这么一个函数的存在,这样函数的调用就不会受到代码顺序的影响。
例子：
比较两数大小并且返回较大的值。
*/
int max(int a, int b); // 声明

int main() {
	cout << max(15,90) << endl;
	return 0;
}

int max(int a, int b) { // 定义
	return a > b ? a : b;
}


