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
	list<int> l1;
	l1.push_front(10);
	l1.push_front(20);
	l1.push_front(30);
	l1.push_front(40);
	printList(l1);

	// 1.operator=赋值
	list<int> l2 = l1;
	printList(l2);

	// 2.assign(区间)赋值
	list<int> l3;
	l3.assign(l2.begin(),l2.end());
	printList(l3);

	// 3.assign(n个element)赋值
	list<int> l4;
	l4.assign(10,9);
	printList(l4);
	
	// 交换函数swap
	cout << "l1和l4交换后：" << endl;
	l1.swap(l4);
	printList(l1);
	printList(l4);

	// list没有capacity的概念，所以交换不能像vector可以节省空间
	return 0;
}
