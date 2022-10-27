#include <iostream>
using namespace std;
#include <functional>
/*
所谓内建的函数对象，就是c++已经帮我们提供好的各种各样的operator()仿函数。
需包含头文件<functional>
*/
int main() {
	// template<typename T> T plus<T>		加法仿函数
	plus<int> p;
	cout << p(100,200) << endl;

	// template<typename T> T minus<T>		减法仿函数
	minus<int> m;
	cout << m(100,200) << endl;

	// template<typename T> T multiplies<T>	乘法仿函数
	multiplies<int> mul;
	cout << mul(30,2) << endl;

	// template<typename T> T divides<T>	除法仿函数
	divides<int> d;
	cout << d(10,3) << endl;

	// template<typename T> T modulus<T>	取模仿函数
	modulus<int> mod;
	cout << mod(11,3) << endl;

	// template<typename T> T negate<T>		取反仿函数
	negate<int> n;
	cout << n(20) << endl;

	return 0;
}
