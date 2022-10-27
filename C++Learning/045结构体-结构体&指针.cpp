#include <iostream>
using namespace std;
/*
利用操作符号 "指针->结构体属性" 可以通过 "指针" 访问结构体属性
*/

int main() {
	// 1.定义结构体
	struct student {
		string name;
		int age;
		int score;
	};

	// 2.创建结构体变量
	student s1 = {"张三",17,99};

	// 3.指针指向结构体变量
	struct student * p  = &s1;

	// 4.用指针访问变量
	cout 	<< p->name	<< endl
			<< p->age	<< endl
			<< p->score	<< endl;
	return 0;
}
