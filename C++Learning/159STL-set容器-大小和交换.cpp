#include <iostream>
using namespace std;
#include <set>
/*

*/
void printSet(const set<int> &s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	};
	cout << endl;
};

int main() {
	set<int> s1;
	cout << "s1.empty() = " << s1.empty() << endl;
	cout << "s1.size() = "  << s1.size()  << endl;
	s1.insert(40);
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	printSet(s1);
	cout << "s1.empty() = " << s1.empty() << endl;
	cout << "s1.size() = "  << s1.size()  << endl << endl;

	set<int> s2;
	s2.insert(100);
	cout << "交换前：" << endl;
	printSet(s1);
	printSet(s2);

	s2.swap(s1);
	cout << "交换后：" << endl;
	printSet(s1);
	printSet(s2);
	
	return 0;
}
