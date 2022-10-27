#include <iostream>
using namespace std;
#include <set>
/*
用set <int,带有升序仿函数的自定义数据类型>
*/
class LaLa {
public:
	bool operator()(int a, int b) {
		return a > b;
	};
};


int main() {
	set<int> s1;
	s1.insert(30);
	s1.insert(20);
	s1.insert(50);
	s1.insert(40);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}; cout << endl;

	set<int, LaLa> s2; // <>中放入带有升序仿函数的自定义数据类型
	s2.insert(30);
	s2.insert(20);
	s2.insert(50);
	s2.insert(40);
	for (set<int, LaLa>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}; cout << endl;

	return 0;
}
