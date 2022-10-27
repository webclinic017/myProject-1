#include <iostream>
using namespace std;
/*
普通函数 和 函数模板 发生重载时的调用规则：
	1、如果普通函数和模板都可以调用，优先调用普通函数。
	2、可以通过空模板的参数列表<>强制调用模板。
	3、模板也可以发生多个重载。
	4、如果模板可以产生更好的匹配，优先调用模板。
*/

void myadd(int a, int b) {
	cout << "调用普通函数" << endl;
};

template<typename T>
void myadd(T a, T b) {
	cout << "调用模板" << endl;
};

void myadd(int a, int b, int c) {
	cout << "调用重载的模板" << endl;
};

int main() {
	int a = 1; int b = 2; int c = 3;
	// 1、如果普通函数和模板都可以调用，优先调用普通函数。
	myadd(a,b);
	// 2、可以通过空模板的参数列表<>强制调用模板。
	myadd<>(a,b);
	// 3、模板也可以发生多个重载。
	myadd(a,b,c);
	// 4、如果模板可以产生更好的匹配，优先调用模板。
	myadd('s','f'); // 如果调用普通函数，编译器还要强制类型转换，编译器不乐意。
	
	return 0;
}
