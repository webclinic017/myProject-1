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
	deque<int> d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i);
	};
	printDeque(d1);
	
	// 三种赋值方法：
	deque<int> d2;
	d2 = d1;
	printDeque(d2);
	
	deque<int> d3;
	d3.assign(d1.begin()+1, d1.end()-1);
	printDeque(d3);

	deque<int> d4;
	d4.assign(5, 9);
	printDeque(d4);
	return 0;
}
