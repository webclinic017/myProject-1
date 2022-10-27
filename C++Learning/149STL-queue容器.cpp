#include <iostream>
using namespace std;
#include <queue>
/*
queue 队列：先进先出 front出 back进
只能访问头和尾，所以不允许便利。
入队 push 出队 pop
*/
class Person {
public:
	string name;
	Person(string name) {
		this->name = name;
	};
};


int main() {
	queue<Person> F4;
	F4.push(Person("唐僧"));
	F4.push(Person("孙悟空"));
	F4.push(Person("猪八戒"));
	F4.push(Person("沙和尚"));
	queue<Person> fake_F4(F4);
	fake_F4 = F4;
	cout << "F4人数：" <<  F4.size() << endl;
	while (!F4.empty()) {
		cout << F4.front().name << "正在打饭，排在最后的 是" << F4.back().name << endl;
		F4.pop();
	};
	cout << "F4人数：" <<  F4.size() << endl;


	cout << "假的F4人数：" <<  fake_F4.size() << endl;
	while (!fake_F4.empty()) {
		cout << "假" << fake_F4.front().name << "正在打饭，排在最后的 是假" << fake_F4.back().name << endl;
		fake_F4.pop();
	};
	cout << "假的F4人数：" <<  fake_F4.size() << endl;



	return 0;
}
