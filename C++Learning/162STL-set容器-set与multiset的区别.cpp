#include <iostream>
using namespace std;
#include <set>
/*

*/

int main() {
	set<int> s;
	pair<set<int>::iterator,bool> res; // set的insert()返回的是这个类型的数据
	res = s.insert(10);
	if (res.second == true) {
		cout << "第一次插入成功" << endl;
	}
	else {
		cout << "第一次插入失败" << endl;
	};

	res = s.insert(10);
	if (res.second == true) {
		cout << "第二次插入成功" << endl;
	}
	else {
		cout << "第二次插入失败" << endl;
	};


	// multiset
	multiset<int> ms;
	ms.insert(10); // 它的返回值就是一个multiset<int>::iterator迭代器,没有bool
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << endl;
	};

	return 0;
}
