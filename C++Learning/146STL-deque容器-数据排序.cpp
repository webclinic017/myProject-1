#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>
/*

*/
void printDeque(deque<int> dec) {
	for (int i = 0; i < dec.size(); i++) {
		cout << dec[i] << " ";
	};
	cout << endl;
};

int main() {
	deque<int> d;
	d.push_back(0);
	d.push_back(40);
	d.push_back(-50);
	d.push_back(30);
	d.push_back(10);
	d.push_back(70);
	d.push_back(-20);
	d.push_back(0);
	cout << "排序前：" << endl;
	printDeque(d);

	sort(d.begin()+1, d.end()-1);
	cout << "排序后：" << endl;
	printDeque(d);





	return 0;
}
