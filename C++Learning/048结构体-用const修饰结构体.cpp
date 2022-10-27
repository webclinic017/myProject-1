#include <iostream>
using namespace std;
/*
值传递 有时候传入的数据量太大，形参会copy一份实参，严重占用内存。
所以用地址传递+const限定符可以做到省内存，也防止实参被修改。
*/

struct student {
	string name;
	int age;
	int score;
};
// const限定符+地址传递  可以防止实参被修改
void printStudent(const struct student * c) {

	// c->age = 100; // const限定符+地址传递  可以防止实参被修改
	cout << "printStudent():" << "姓名：" << c->name  << endl;
	cout << "printStudent():" << "年龄：" << c->age   << endl;
	cout << "printStudent():" << "分数：" << c->score << endl;

};

int main() {
	struct student s = {"tom",28,95};

	printStudent(&s);
	
	return 0;
}
