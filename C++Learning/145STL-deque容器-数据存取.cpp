#include <iostream>
using namespace std;
#include <deque>
/*

*/

int main() {
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(-10);
	d.push_front(-20);
	d.push_front(-30);

	// 用[]方式访问
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	};	cout << endl;

	// 用at方式访问
	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << " ";
	};	cout << endl;

	cout << "访问头：" << d.front() << endl;
	cout << "访问尾：" << d.back() << endl;

	return 0;
}
