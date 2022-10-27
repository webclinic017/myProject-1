#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
算法常用的头文件：
	algorithm、numeric、functional
adjacent_find(起始迭代器、结束迭代器)
	查找相邻且重复的元素返回找到的第一个元素的迭代器
*/
class myPrint {
public:
	void operator()(int num) {
		cout << num << " ";
	};
};

int main() {
	vector<int> v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(4);
	v.push_back(1);
	v.push_back(5);
	v.push_back(5);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	while (true) {
		vector<int>::iterator it = adjacent_find(v.begin(), v.end());
		if (it == v.end()) {
			cout << endl;
			cout << "相邻且重复的元素已经处理完成" << endl;
			cout << "处理完后的vector：" << endl;
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}; cout << endl;
			break;
		}
		else {
			cout << "找到相邻且重复的元素" << *it << ", 现在删除它" << endl;
			v.erase(it);
		};
	};




	return 0;
}
