#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
算法常用的头文件：
	algorithm、numeric、functional
find_if(起始迭代器、结束迭代器、谓词的函数对象)
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

class myRule1 {
public:
	bool operator()(int num) {
		return num > 5;
	};
};

class myRule2 {
public:
	bool operator()(const Person &p) {
		return p.name == "刘备" and p.age <= 30;
	};
};

int main() {
	// 1.查找内置数据类型 （如 int）
	vector<int> v1;
	for (int i = 1; i <= 10; i++) 
		{v1.push_back(i);};
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), myRule1());
	if (it == v1.end()) {cout << "没找到数字" << endl;}
	else {cout << "找到符合要求的数字:" << *it << endl;};


	// 2.查找自定义的数据类型
	vector<Person> v2;
	v2.push_back(Person("刘备",32));
	v2.push_back(Person("关羽",29));
	v2.push_back(Person("张飞",28));
	v2.push_back(Person("赵云",24));
	v2.push_back(Person("刘备",15));
	vector<Person>::iterator it2 = find_if(v2.begin(),v2.end(),myRule2());
	if (it2 == v2.end()) {cout << "没找到人物" << endl;}
	else {cout << "找到符合要求的人物:" << it2->name << " 年龄：" << it2->age << endl;};
	return 0;
}
