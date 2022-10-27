#include <iostream>
using namespace std;
/*
继承中的构造\析构顺序：
	先构造父类，再构造子类；析构顺序与之相反。
*/
class Father {
public:
	Father() {
		cout << "父类的构造函数" << endl;
	};
	~Father() {
		cout << "父类的析构函数" << endl;
	};
};

class Son : public Father {
public:
	Son() {
		cout << "子类的构造函数" << endl;
	};
	~Son() {
		cout << "子类的析构函数" << endl;
	};
};

int main() {
	Son s1;
	return 0;
}
