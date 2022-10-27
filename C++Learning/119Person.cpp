#include "119Person.h"

// 1.构造函数的类外实现
template<typename T1, typename T2> // 必须再次定义模板
Person<T1,T2>::Person(T1 name, T2 age) { // 作用域后要加相应的模板参数
	this->name = name; this->age = age;
};

// 2.成员函数类外实现
template<typename T1, typename T2>
void Person<T1,T2>::show() {
	cout << "姓名：" << this->name << "\t年龄：" << this->age << endl;
};
