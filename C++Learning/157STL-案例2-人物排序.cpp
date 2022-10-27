#include <iostream>
using namespace std;
#include <list>
/*
要求：
	人物安装年龄从小到大排序；如果年龄一致安装升高从大到小排序。
*/
class Person {
public:
	string name;
	int age;
	float height;
	Person(string name, int age, float height) {
		this->name = name;
		this->age = age;
		this->height = height;
	};
};

void printList(const list<Person> &L) {
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名：" << (*it).name << "  年龄：" << it->age << "  身高：" << it->height << endl;
	};
};

bool myComparePerson(Person &p1, Person &p2) {
	if (p1.age < p2.age) {
		return true;
	}
	else if (p1.age > p2.age) {
		return false;
	}
	else if (p1.height < p2.height) {
		return false;
	}
	else {
		return true;
	};
};

int main() {
	list<Person> l;
	l.push_back(Person("刘备", 35, 175.5));
	l.push_back(Person("曹操", 45, 180.1));
	l.push_back(Person("孙权", 40, 170.4));
	l.push_back(Person("赵云", 25, 190.7));
	l.push_back(Person("张飞", 35, 165.9));
	l.push_back(Person("关羽", 35, 200.2));
	cout << "排序前：" << endl;
	printList(l);
	l.sort(myComparePerson);  //自定义数据类型排序需要自己提供算法函数，将函数名写入sort(中)。
	cout << "排序后：" << endl;
	printList(l);
	return 0;
}
