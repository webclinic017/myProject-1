#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
reverse 反转
*/
void myPrint(int num) {
	cout << num << " ";
};

int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "反转前：" << endl;
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;

	cout << "反转后：" << endl;
	reverse(v.begin(),v.end());
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;
	return 0;
}
