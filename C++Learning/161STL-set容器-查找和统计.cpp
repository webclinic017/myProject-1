#include <iostream>
using namespace std;
#include <set>
/*

*/

int main() {
	set<int> s;
	s.insert(20);
	s.insert(30);
	s.insert(10);
	s.insert(40);

	// 查找 iterator set.find(element) {}
	set<int>::iterator pos = s.find(30);
	if (pos != s.end()) {
		cout << "找到元素" << *pos << endl;
	}
	else {
		cout << "没找到" << endl;
	};

	// 统计 set.count() 对于set而言，要不就没找到，要不就找到了1个。
	cout << "统计的个数为" << s.count(0) << endl;
	return 0;
}
