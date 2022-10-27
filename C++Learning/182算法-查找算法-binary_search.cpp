#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <algorithm>
/*
算法常用的头文件：
	algorithm、numeric、functional
返回值bool = binary_search(起始迭代器、结束迭代器、查找的目标)
	二分查找必须是有序的序列，否则结果不一定对
*/

int main() {
	vector<int> v;
	v.push_back(5);
	v.push_back(6);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	bool res1 = binary_search(v.begin(),v.end(),1);
	if (res1) {cout << "找到了" << endl;} else {cout << "没找到" << endl;};
	sort(v.begin(),v.end()); // 二分查找必须是有序的序列，否则结果不一定对
	res1 = binary_search(v.begin(),v.end(),1);
	if (res1) {cout << "找到了" << endl;} else {cout << "没找到" << endl;};
	
	set<int> s;
	s.insert(5);
	s.insert(6);
	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(2);
	bool res2 = binary_search(s.begin(),s.end(),1);
	if (res2) {cout << "找到了" << endl;} else {cout << "没找到" << endl;};
	return 0;
}
