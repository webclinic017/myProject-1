#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
swap(容器1，容器2) 注意两个容器要是同类容器
	注：vector<int> 和 vector<string> 交换也不可以
*/
class myPrint {
public:
	void operator()(int num) {
		cout << num << " ";
	};
	void operator()(string str) {
		cout << str << " ";
	};
};

int main() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(2);

	vector<int> v2;
	v2.push_back(20);
	v2.push_back(10);

	cout << "交换后：" << endl;
	swap(v1,v2);
	cout << "v1：";
	for_each(v1.begin(),v1.end(),myPrint());
	cout << endl;

	cout << "v2：";
	for_each(v2.begin(),v2.end(),myPrint());
	cout << endl;
	return 0;
}
