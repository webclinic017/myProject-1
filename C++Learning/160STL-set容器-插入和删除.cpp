#include <iostream>
using namespace std;
#include <set>
/*

*/
void printSet(const set<int> &s) {
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
 	};
	cout << endl;
};

int main() {
	set<int> s;
	// 插入
	s.insert(30);
	s.insert(40);
	s.insert(10);
	s.insert(20);
	printSet(s);
	// 删除
	s.erase(s.begin());
	// s.erase(s.begin(),s.end());
	printSet(s);

	// 删除的重构
	s.erase(30);
	printSet(s);

	// 清空
	s.clear();
	printSet(s);

	
	return 0;
}
