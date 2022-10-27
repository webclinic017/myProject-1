#include <iostream>
using namespace std;
/*
1.如果父类是类模板，子类在继承时必须指定父类的T的类型，否则编译器无法确定分配多少内存。
2.如果想灵活指出父类中T的类型，子类也需要变为类模板。
*/
template<typename T>
class Father {
public:
	T any;
};

class Son1 : public Father<int> {
	string sonName;
};

template<typename T_f>
class Son2 : public Father<T_f> {
	string sonName;
};

template<typename T_f, typename T_s>
class Son3 : public Father<T_f> {
	T_s sonAny;
};

int main() {
	Son1 s1;
	Son2<char> s2; // char 给的是父类的数据类型
	Son3<double, string> s3; // double 给的是父类的数据类型 string 给的是子类的数据类型
	return 0;
}
