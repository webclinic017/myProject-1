#include <iostream>
using namespace std;
/*
记忆口诀：顺序翻译
const int * ：(翻译)常量指针。const修饰的是*，那么取*的操作做不了。
int * const : (翻译)指针常量。const修饰的是p，那么p=??的操作做不了。
*/

int main() {
	int a = 10;
	int b = 20;

	/*
	常量指针：const 数据类型 * 指针名 = &变量命；
	指针的指向可以变，指针指向的变量值不可变。
	*/
	const int * p = &a;
	cout << "修改前：" << endl;
	cout << a << endl;
	cout << b << endl;
	cout << p << endl;
	cout << *p << endl << endl;
	// *p = 30; // wrong 表达式必须是可修改的左值
	p = &b;
	cout << "修改后：" << endl;
	cout << a << endl;
	cout << b << endl;
	cout << p << endl;
	cout << *p << endl;
	cout << "=====================" << endl << endl;


	/*
	指针常量：数据类型 * const 指针名 = &变量命；
	指针的指向不可以变，指针指向的变量值可变。
	*/
	int * const q = &a;
	cout << "修改前：" << endl;
	cout << a << endl;
	cout << b << endl;
	cout << q << endl;
	cout << *q << endl << endl;
	// q = &b; // wrong 表达式必须是可修改的左值
	*q = 30; 
	cout << "修改后：" << endl;
	cout << a << endl;
	cout << b << endl;
	cout << q << endl;
	cout << *q << endl;
	cout << "=====================" << endl << endl;


	/*
	既修饰指针，又修饰常量：const 数据类型 * const 指针名 = &变量命；
	指针的指向，指针指向的变量值都不可变。
	*/
	const int * const r = &a;
	// r = &b; // wrong
	// *r = 90; // wrong
	return 0;
}
