#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
算法常用的头文件：
	algorithm、numeric、functional
find(起始迭代器、结束迭代器、内置数据类型或自定义数据类型)
*/

// 1.查找内置数据类型
void test01() {
	vector<string> v;
	v.push_back("刘备");
	v.push_back("关羽");
	v.push_back("张飞");
	v.push_back("赵云");
	vector<string>::iterator it = find(v.begin(),v.end(),"张飞");
	if (it == v.end()) {
		cout << "没找到" << endl;
	}
	else {
		cout << "找到了数据：" << *it << endl;
	};
};

// 2.查找自定义的数据类型
class Person {
public:
	string name;
	int age;
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	};
	// 对于自定义数据类型必须在类型里重载==号才能让编译器懂得对比
	bool operator==(const Person &p) {
		return this->name == p.name and this->age == p.age;
	};
};

void test02() {
	vector<Person> v;
	v.push_back(Person("刘备",39));
	v.push_back(Person("关羽",36));
	v.push_back(Person("张飞",32));
	v.push_back(Person("赵云",28));
	vector<Person>::iterator it = find(v.begin(),v.end(),Person("赵云",27));
	if (it == v.end()) {
		cout << "没找到" << endl;
	}
	else {
		cout << "找到了数据：" << it->name << ", " << it->age << endl;
	};
};





int main() {
	test01();
	test02();
	return 0;
}
