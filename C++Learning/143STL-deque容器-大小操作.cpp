#include <iostream>
using namespace std;
#include <deque>
/*
d1.size()
d1.empty()
d1.resize(n,ele)
*/

void printDeque(const deque<int> &d) {
	for (deque<int>::const_iterator ci = d.begin(); ci != d.end(); ci++) {
		cout << *ci << ' ';
	};
	cout << endl;
};

int main() {
	deque<int> d1;
	printDeque(d1);
	cout << "size of deque = " << d1.size() << endl;
	cout << "是否为空:" << d1.empty() << endl << endl;

	for (int i = 1; i <= 10; i++) {
		d1.push_back(i);
	};
	printDeque(d1);
	cout << "size of deque = " << d1.size() << endl;
	cout << "是否为空:" << d1.empty() << endl << endl;

	d1.resize(3);
	printDeque(d1);
	cout << "size of deque = " << d1.size() << endl;
	cout << "是否为空:" << d1.empty() << endl << endl;

	d1.resize(13,1);
	printDeque(d1);
	cout << "size of deque = " << d1.size() << endl;
	cout << "是否为空:" << d1.empty() << endl << endl;

	return 0;
}
