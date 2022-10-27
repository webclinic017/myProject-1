#include <iostream>
using namespace std;
#include <list>
/*

*/
void printList(const list<int> &L) {
	for (list<int>::const_iterator cit = L.begin(); cit != L.end(); cit++) {
		cout << *cit << " ";
	};
	cout << endl;
};

int main() {
	// 1.默认构造
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);
	
	// 2.区间方式构造
	list<int> l2(l1.begin(), l1.end());
	printList(l2);

	// 3.n个ele方式构造
	list<int> l3(5,3);
	printList(l3);

	// 4.拷贝构造
	list<int> l4(l3);
	printList(l4);
	return 0;
}
