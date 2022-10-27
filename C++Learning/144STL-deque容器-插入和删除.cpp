#include <iostream>
using namespace std;
#include <deque>
/*

*/
void printDeque(const deque<int> &d) {
	for (deque<int>::const_iterator ci = d.begin(); ci != d.end(); ci++) {
		cout << *ci << ' ';
	};
	cout << endl;
};

int main() {
	deque<int> d;
	//1.尾插
	d.push_back(10);
	d.push_back(15);

	//2.头插
	d.push_front(5);
	d.push_front(0);
	printDeque(d);

	//3.尾删
	d.pop_back();

	//4.头删
	d.pop_front();
	printDeque(d);

	//5.insert插入
	d.insert(d.begin(),-100);
	printDeque(d);
	d.insert(d.begin(),2,-200);
	printDeque(d);
	d.insert(d.begin(),d.end()-1,d.end()); // d.insert(pos迭代器,a,b) [a,b) 插入前闭后开的deque
	printDeque(d);

	//6.erase删除
	d.erase(d.begin()+2);
	printDeque(d);
	d.erase(d.begin()+1,d.end()-1);
	printDeque(d);

	//7.clear删除
	d.clear();
	printDeque(d);

	return 0;
}
