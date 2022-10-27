#include <iostream>
using namespace std;
/*
重载递增运算符，实现自定义数据的递增。
*/

class MyInt {
private:
	int myint;
public:
	MyInt() {myint = 0;};
	void show() {cout << this->myint << endl;};

	// 前置递增：返回值必须是引用，不然每次都会返回不同内存地址的新的对象，数字加不上去
	MyInt& operator++() {
		this->myint++;
		return *this;
	};

	// 后置递增：参数用一个int作占位参数，用以和前置递增区分开;返回值不能是引用，因为它是局部变量（函数结束会消失）。
	MyInt operator++(int) {
		MyInt tmp;
		tmp.myint = this->myint;
		this->myint++;
		return tmp;
	};

	// 前置递减：返回值必须是引用，不然每次都会返回不同内存地址的新的对象，数字减不下去
	MyInt& operator--() {
		this->myint--;
		return *this;
	};

	// 后置递减：参数用一个int作占位参数，用以和前置递减区分开;返回值不能是引用，因为它是局部变量（函数结束会消失）。
	MyInt operator--(int) {
		MyInt tmp;
		tmp.myint = this->myint;
		this->myint--;
		return tmp;
	};

};


int main() {
	MyInt i;
	i.show();
	++i;
	++i;
	++i;
	i.show();
	i++;
	i++;
	i++.show();
	i.show();

	cout << endl;
	
	--i;
	--i;
	--i;
	i.show();
	i--;
	i--;
	i--.show();
	i.show();

	return 0;
}