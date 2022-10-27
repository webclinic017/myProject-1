#include <iostream>
using namespace std;
/*
除了构造函数，我们还可以用初始化列表来做属性的初始化。
初始化列表语法：
	构造函数():属性(值),属性(值).属性(值),.....

!!! 用初始化列表必须提供析构函数，不然会报错，不知道为啥。
*/

class Person {

public:
	int age;
	int height;
	int heavy;

	Person():age(18),height(160),heavy(50) {
		cout << "Person的无参构造函数" << endl;
	};

	Person(int a, int b, int c):age(a),height(b),heavy(c) {
		cout << "Person的有参构造函数" << endl;
	};
	
	

	// Person(int a) {
	// 	age = a;
	// 	cout << "Person的有参构造函数" << endl;
	// };

	// 即使我们把拷贝构造注视掉，c++也会提供默认的copy构造函数
	/*
	Person(const Person &p) {
		age = p.age;
		cout << "Person的copy构造函数" << endl;
	};
	*/

	~Person() {
		cout << "Person的析构函数" << endl;
	};
};


int main() {
	
	Person p1;
	cout << "p1.age = " << p1.age << endl;
	cout << "p1.height = " << p1.height << endl;	
	cout << "p1.heavy = " << p1.heavy << endl;	
	cout << " ====================================== " << endl;

	Person p2(1,1,1);
	cout << "p2.age = " << p2.age << endl;
	cout << "p2.height = " << p2.height << endl;	
	cout << "p2.heavy = " << p2.heavy << endl;	
	return 0;
}
