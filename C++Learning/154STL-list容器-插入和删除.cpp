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
	l.assign(4,8);

	// 1.头尾插
	l.push_front(1);
	l.push_back(1);
	printList(l);

	// 2.头尾删
	l.pop_front();
	l.pop_back();
	printList(l);

	// 3.insert插入
	list<int>::iterator it = l.begin(); it++; it++;
	l.insert(it,100);
	printList(l);

	l.insert(it,2,200);
	printList(l);

	// 4.erase删除
	it = l.begin(); it++; it++;
	l.erase(it);
	printList(l);

	list<int>::iterator it1 = l.begin(); it1++; it1++;
	list<int>::iterator it2 = l.end(); it2--; it2--;
	l.erase(it1, it2);
	printList(l);

	// 5.remove移除
	l.resize(20,1);
	l.remove(8);
	printList(l);	

	// 6.清空
	l.clear();
	printList(l);
	return 0;
}
