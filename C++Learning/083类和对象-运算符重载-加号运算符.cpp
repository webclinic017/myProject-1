#include <iostream>
using namespace std;
/*

*/
class Person {
public:
	int age;
	int score;
	// 一、在成员函数中重载运算符
	// Person operator+ (Person &p);
};
// 一、在成员函数中重载运算符
// Person Person::operator+ (Person &p) {
// 	Person tmp;
// 	tmp.age = this->age + p.age;
// 	tmp.score = this->score + p.score;
// 	return tmp;
// };

// 二、在全局函数中重载运算符
Person operator+(Person &p1, Person &p2) {
	Person tmp;
	tmp.age = p1.age + p2.age;
	tmp.score = p1.score + p2.score;
	return tmp;
};

Person operator+(Person &p1, int a) {
	Person tmp;
	tmp.age = p1.age + a;
	tmp.score = p1.score + a;
	return tmp;
};

int main() {
	Person p1;
	p1.age = 10;
	p1.score = 10;
	
	Person p2;
	p2.age = 20;
	p2.score = 20;

	Person p3 = p1 + p2;
	cout << "p3.age = " << p3.age << endl;
	cout << "p3.score = " << p3.score << endl;

	Person p4 = p1 + 1;
	cout << "p4.age = " << p4.age << endl;
	cout << "p4.score = " << p4.score << endl;
	return 0;
}
