#include <iostream>
using namespace std;
#include <list>
/*

*/
void printList(const list<int> &L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	};
	cout << endl;
};

int main() {
	list<int> l;
	cout << "l.empty() = " << l.empty() << endl;
	cout << "l.size() = " << l.size() << endl;

	for (int i = 1; i <= 5; i++) {
		l.push_front(i);
	};
	printList(l);
	cout << "l.empty() = " << l.empty() << endl;
	cout << "l.size() = " << l.size() << endl;

	l.resize(10);
	printList(l);
	cout << "l.empty() = " << l.empty() << endl;
	cout << "l.size() = " << l.size() << endl;

	l.resize(15,999);
	printList(l);
	cout << "l.empty() = " << l.empty() << endl;
	cout << "l.size() = " << l.size() << endl;

	

	
	return 0;
}
