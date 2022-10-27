#include <iostream>
using namespace std;
/*
多继承：一个儿子多个爹
语法：
	class 子类名 : 继承方法 父类名1 , 继承方法 父类名2 {}
*/
class Father1 {
public:
	int age = 45;
};

class Father2 {
public:
	int age = 51;
};

class Son : public Father1 , public Father2 {
public:
	int score = 95;
};

int main() {
	Father1 f1;
	Father2 f2;
	Son s;
	cout << "sizeof father1: " << sizeof(f1) << endl;
	cout << "sizeof father2: " << sizeof(f2) << endl;
	cout << "sizeof son: " << sizeof(s) << endl << endl;

	cout << "son's score: " << s.score << endl;
	cout << "father1's age: " << s.Father1::age << endl;
	cout << "father2's age: " << s.Father2::age << endl;

	return 0;
}
