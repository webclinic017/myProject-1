#include <iostream>
using namespace std;
#include <set>
/*
当用set插入自定义的数据类型的时候set必须使用仿函数，否则set不知道如何排序。
*/
class Person {
public:
	string name;
	int age;
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	};
};

class myRule {
public:
	bool operator()(const Person &p1, const Person &p2) { // 重载operator()
		if (p1.age > p2.age) {
			return true;
		}
		else {
			return false;
		};
	};
};

int main() {
	set<Person, myRule> s; // <>中放入带有升序仿函数的自定义数据类型
	s.insert(Person("张飞", 28));
	s.insert(Person("刘备", 32));
	s.insert(Person("赵云", 26));
	s.insert(Person("关羽", 29));

	for (set<Person,myRule>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "姓名：" << it->name << " 年龄：" << it->age << endl;
	};
	
	return 0;
}
