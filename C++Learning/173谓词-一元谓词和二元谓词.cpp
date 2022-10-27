#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
谓词(_Pred)：
	返回值是bool的仿函数
	如果bool operator()(参数1) 只有一个参数 叫做一元谓词
	如果bool operator()(参数1,参数2) 有两个参数 叫做二元谓词
*/

// 1.一元谓词
class myRule1 {
public:
	bool operator()(int a) {
		return a>5;
	};
};
void test01() {
	vector<int>	v;
	for (int i = -5; i <= 9; i++) {
		v.push_back(i);
	};
	myRule1 mr;
	vector<int>::iterator it = find_if(v.begin(),v.end(),mr); // find_if 标准算法：返回值迭代器，参数（区间前，区间后，谓词对象）
	if (it != v.end()) {
		cout << "找到了大于5的数字" << *it << endl;
	}
	else {
		cout << "没找到大于5的数字" << endl;
	};
};

// 2.二元谓词
class myRule2 {
public:
	bool operator()(int num1, int num2) {
		return num1 > num2;
	};
};
void printVector(const vector<int> &v) {
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}; cout << endl;
};
void test02() {
	vector<int> v;
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(10);
	v.push_back(40);
	printVector(v);
	sort(v.begin(),v.end());
	printVector(v);
	sort(v.begin(),v.end(),myRule2()); // myRule2()匿名对象
	printVector(v);
};

int main() {
	test01();
	test02();
	return 0;
}
