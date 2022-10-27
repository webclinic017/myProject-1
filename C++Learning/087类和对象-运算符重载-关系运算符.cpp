#include <iostream>
using namespace std;
/*

*/

class Person {
private:
	string name;
	int age;
public:
	Person(string n, int a) {
		name = n;
		age = a;
	};
	bool operator==(Person &p) {
		if (name == p.name and age == p.age) {
			return true;
		}
		else {
			return false;
		}
	};
	bool operator!=(Person &p) {
		if (name == p.name and age == p.age) {
			return false;
		}
		else {
			return true;
		}
	};
};


int main() {
	Person p1("张三",19);
	Person p2("张三",19);
	if (p1 == p2) {
		cout << "p1和p2相等" << endl;
	}
	else {
		cout << "p1和p2不相等" << endl;
	}

	if (p1 != p2) {
		cout << "p1和p2不相等" << endl;
	}
	else {
		cout << "p1和p2相等" << endl;
	}
	return 0;
}
