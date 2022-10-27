#include <iostream>
using namespace std;
/*
如果用指针作为函数的形参，函数的实参会随着形参（指针）的改变而改变。
当想要某个函数去改变实参的值时，可以用指针作为形参。
*/


void change(int * p1, int * p2){ //两个内存地址（指针）
	int temp = *p1; // 指针解引用
	*p1 = *p2;
	*p2 = temp;
}


int main() {
	int tom = 10;
	int jerry = 20;
	cout << "tom and jerry 交换前：" << endl;
	cout << "tom = " << tom << ", jerry = " << jerry << endl << endl;
	change(&tom, &jerry);
	cout << "tom and jerry 交换后：" << endl;
	cout << "tom = " << tom << ", jerry = " << jerry << endl << endl;
	return 0;
}