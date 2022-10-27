#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
算法常用的头文件：
	algorithm、numeric、functional
返回值int = count_if(起始迭代器、结束迭代器、谓词)
*/

// 1.count_if统计内置数据类型
bool GreaterThen20(int num) 
	{return num > 20;};

void test01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(40);
	v.push_back(30);
	int num = count_if(v.begin(),v.end(),GreaterThen20);
	cout << "大于20的数字有" << num << "个" << endl;
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
};

class olderThen30 {
public:
	bool operator()(const Person &p) {
		return p.age > 30;
	};
};

void test02() {
	vector<Person> v;
	v.push_back(Person("刘备",38));
	v.push_back(Person("关羽",32));
	v.push_back(Person("张飞",32));
	v.push_back(Person("赵云",29));
	int num = count_if(v.begin(),v.end(),olderThen30());
	cout << "大于30岁的人有" << num << "个" << endl;
};





int main() {
	test01();
	test02();
	return 0;
}
