#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
replace_if(起始迭代器，结束迭代器，谓词，新值)
*/
void myPrint(int num) {
	cout << num << " ";
};

class myRule {
public:
	bool operator()(int num) {
		return num > 30;
	};
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
	replace_if(v.begin(),v.end(),myRule(),1000);
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;

}
