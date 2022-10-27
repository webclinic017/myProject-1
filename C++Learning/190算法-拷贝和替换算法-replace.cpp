#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
replace(起始迭代器，结束迭代器，原值，新值)
*/
void myPrint(int num) {
	cout << num << " ";
};

int main() {
	vector<int> v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	cout << "替换前：" << endl;
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;
	
	cout << "替换后：" << endl;
	replace(v.begin(),v.end(),20,2000);
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;

}
