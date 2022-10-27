#include <iostream>
using namespace std;
/* 
不同区的数据有自己的不同的生命周期。
	代码区：所有的代码（转成二进制 "a.out" "a.exe"）
		共享性：二进制代码在运行中是共享的，可以被需要它的东西频繁执行。
		只读性：二进制代码在运行中是只读的，不可被改变。
	全局区：全局变量、静态变量、常量（字符串常量、全局常量）
		在程序结束后由操作系统管理它的消亡。
	栈区：局部变量、函数参数等
		栈区的数据由编译器开辟、管理和释放。所以不要返回局部变量的地址。
	堆区：由程序员开辟、管理和释放。
*/

// 1.全局变量
int globalA = 10;
int globalB = 20;

// 3.2 （全局常量） const修饰的全局变量 
const int const_globalA = 10;
const int const_globalB = 20;



void quanJuQu() {
	// 局部变量
	int A = 10;
	int B = 20;
	// 2.静态变量
	static int staticA = 10;
	static int staticB = 20;
	// 3.1 字符串常量
	// "hello";
	// "world";
	// 3.3 （局部常量） const修饰的局部变量
	const int const_A = 10;
	const int const_B = 20;

	cout << "局部变量A的地址: \t\t" 	  << (int)&A << endl;
	cout << "局部变量B的地址: \t\t" 	  << (int)&B << endl;
	cout << "全局变量globalA的地址: \t\t" << (int)&globalA << endl;
	cout << "全局变量globalB的地址: \t\t" << (int)&globalB << endl;
	cout << "静态变量staticA的地址: \t\t" << (int)&staticA << endl;
	cout << "静态变量staticB的地址: \t\t" << (int)&staticB << endl;
	cout << "字符串常量\"hello\"的地址: \t" << (int)&"hello" << endl;
	cout << "字符串常量\"world\"的地址: \t" << (int)&"world" << endl;
	cout << "全局常量const_globalA的地址: \t" << (int)&const_globalA << endl;
	cout << "全局常量const_globalB的地址: \t" << (int)&const_globalB << endl;
	cout << "局部常量const_A的地址: \t\t" << (int)&const_A << endl;
	cout << "局部常量const_B的地址: \t\t" << (int)&const_B << endl;
};

int * zhanQu() {
	// 栈区的数据由编译器开辟、管理和释放。所以不要返回局部变量的地址。
	int a = 10; // 数据存放在栈区，栈区的数据在函数执行完后释放。
	return &a; // 所以不要返回局部变量的地址。
};

int * duiQu() {
	// 堆区：由程序员开辟、管理和释放。
	// 利用new关键字 可以将数据开辟到堆区
	int * p = new int(10); // 利用指针去接收“new”开辟的内存地址
	return p;
};

int main() {
	quanJuQu();
	int * q = duiQu(); // 用指针接收返回值
	cout << "堆区：" << *q << endl; // 解引用 拿到数据

	int * p = zhanQu(); // 用指针接收返回值
	cout << "栈区：" << *p << endl; // 解引用 拿到数据（报错）
};