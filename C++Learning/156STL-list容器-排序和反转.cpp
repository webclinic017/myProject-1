#include <iostream>
using namespace std;
#include <list>
#include <algorithm>
/*

*/
void printList(const list<int> &L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	};
	cout << endl;
};

bool myCompare(int a, int b) {
	if (a > b) {return true;} else {return false;};
};

int main() {
	list<int> l;
	l.push_back(20);
	l.push_back(40);
	l.push_back(30);
	l.push_back(50);
	l.push_back(10);

	cout << "反转前: " << endl;
	printList(l);
	
	l.reverse();
	cout << "反转后: " << endl;
	printList(l);


	// 1.所有不具备随机访问性的容器都不支持algorithm的算法函数
	// sort(l.begin(), l.end()); // 报错
	// 2.所有不具备随机访问性的容器内部都会提供排序算法
	l.sort(); //默认升序
	cout << "排序后: " << endl;
	printList(l);
	
	cout << "降序排序后: " << endl;
	l.sort(myCompare); //降序需要自己提供算法函数，将函数名写入sort(中)。
	printList(l);

	return 0;
}
