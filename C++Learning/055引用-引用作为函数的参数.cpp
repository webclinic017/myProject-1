#include <iostream>
using namespace std;
/*
引用传递的形参的操作会改变实参。和指针传递一样
*/

// swap 交换函数
// 1、值传递
void swap01(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
};

// 2、地址传递
void swap02(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
};

// 3、引用传递
void swap03(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
};

int main() {
	int tom = 10; int jerry = 20;
	// 1、值传递
	swap01(tom, jerry);
	cout << "tom:" << tom << "  jerry:" << jerry << endl;

	// 2、地址传递
	tom = 10; jerry = 20;
	swap02(&tom, &jerry);
	cout << "tom:" << tom << "  jerry:" << jerry << endl;

	// 3、引用传递
	tom = 10; jerry = 20;
	swap03(tom, jerry);
	cout << "tom:" << tom << "  jerry:" << jerry << endl;
	
	return 0;
};