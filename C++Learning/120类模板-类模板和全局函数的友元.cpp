#include <iostream>
using namespace std;
/*
友元的全局模板函数的类外实现比较复杂：
*/

// 类外实现步骤一：先要编译器知道有个类模板叫Person
template<typename T1, typename T2>
class Person;

// 类外实现步骤二：再要编译器知道有个全局的模板函数，并且实现好（要用到上面的类模板）
template<typename T1, typename T2>
void show2(Person<T1,T2> &p) {cout << "姓名：" << p.name << "\t年龄：" << p.age << endl;};



template<typename T1, typename T2>
class Person {

// 方式1.利用友元friend在类内声明一个全局模板函数，并且直接在类内把函数实现做掉。
friend void show1(Person<T1,T2> &p) {cout << "姓名：" << p.name << "\t年龄：" << p.age << endl;};

// 方式2.利用友元friend，友元到类外的全局模板函数。
// 类外实现步骤三：做友元。注意：show2后必须加<>,为了使编译器知道这是一个模板函数，而不是普通函数。
friend void show2<>(Person<T1,T2> &p);  


public:
	Person(T1 name, T2 age) {
		this->name = name; this->age = age;
	};
private:
	T1 name;
	T2 age;
};






int main() {
	Person<string, int> p1("张三",19);
	Person<string, int> p2("李四",21);
	show1(p1); // 类内实现的全局模板函数
	show2(p2); // 类外实现的全局模板函数
	return 0;
}

