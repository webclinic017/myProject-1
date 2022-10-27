#include <iostream>
using namespace std;
#include <deque>
/*
双端数组：deque
*/
void printDeque(const deque<int> &d) {
	for (deque<int>::const_iterator ci = d.begin(); ci != d.end(); ci++) {
		cout << *ci << ' ';
		// *ci = 100; // 这样它就变为只读了。
	};
	cout << endl;
};

int main() {
	// 四种构造方法：
	deque<int> d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i);
	};
	printDeque(d1);

	deque<int> d2(d1.begin()+1, d1.end()-1);
	printDeque(d2);

	deque<int> d3(5,9);
	printDeque(d3);

	deque<int> d4(d3);
	printDeque(d4);
	return 0;
}
