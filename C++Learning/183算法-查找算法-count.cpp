#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
算法常用的头文件：
	algorithm、numeric、functional
返回值int = count(起始迭代器、结束迭代器、内置数据类型或自定义数据类型)
*/

// 1.统计内置数据类型
void test01() {
	vector<string> v;
	v.push_back("赵云");
	v.push_back("刘备");
	v.push_back("关羽");
	v.push_back("赵云");
	v.push_back("张飞");
	v.push_back("赵云");
	int num = count(v.begin(),v.end(),"赵云");
	cout << "名字叫赵云的人有" << num << "个" << endl;
};

// 2.统计自定义的数据类型
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
		return  this->age == p.age;
	};
};

void test02() {
	vector<Person> v;
	v.push_back(Person("刘备",38));
	v.push_back(Person("关羽",32));
	v.push_back(Person("张飞",32));
	v.push_back(Person("赵云",29));
	int num = count(v.begin(),v.end(),Person("孙权",32));
	cout << "和孙权同岁的人有" << num << "个" << endl;
};





int main() {
	test01();
	test02();
	return 0;
}
