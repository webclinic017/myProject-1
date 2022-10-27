#include <iostream>
using namespace std;
#include <vector>
/*

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




int main() {
	Person p1("aaa",10); Person p2("bbb",20); Person p3("ccc",30); Person p4("ddd",40);
	// 1.vector容器中存放Person数据类型。
	vector<Person> v;
	v.push_back(p1); v.push_back(p2); v.push_back(p3); v.push_back(p4);
	// 遍历：
	for (vector<Person>::iterator it = v.begin(); it < v.end(); it++) {
		cout << "遍历方式1 姓名：" << (*it).name << "  年龄：" << (*it).age << endl;
		cout << "遍历方式2 姓名：" << it->name << "  年龄：" << it->age << endl; // 从尖括号中可以看出：it就是Person类的一个指针
	};

	// 2.vector容器中存放Person数据类型的指针。
	vector<Person *> v2;
	v2.push_back(&p1); v2.push_back(&p2); v2.push_back(&p3); v2.push_back(&p4); //需要写取址符号& 使得传入的是一个地址。
	// 遍历：
	for (vector<Person *>::iterator it2 = v2.begin(); it2 < v2.end(); it2++) {
		cout << "姓名：" << (*it2)->name << "  年龄：" << (*it2)->age << endl; // 从尖括号中可以看出：*it2就是Person *的一个指针
	};
	
	return 0;
}
