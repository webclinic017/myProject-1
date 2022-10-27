#include <iostream>
using namespace std;
#include <map>
/*

*/
class myRule {
public:
	// bool operator()(const pair<int,string> &p1, const pair<int,string> &p2) // 大错：map只能按照key排序，你传入一个pair什么意思？想让它按value排序吗？
	bool operator()(const int a, const int b)
	{
		return a > b;
	};
};


void printMap(const map<int,string,myRule> &m) {
	for (map<int,string,myRule>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << "序号：" << it->first << " 姓名：" << it->second << endl;
	};
};


int main() {
	map<int,string,myRule> m;
	m.insert(make_pair(1,"刘备"));
	m.insert(make_pair(2,"关羽"));	
	m.insert(make_pair(3,"张飞"));	
	m.insert(make_pair(4,"赵云"));
	m.insert(pair<int,string>(5,"貂蝉"));
	m.insert(pair<int,string>(6,"大乔"));
	m.insert(pair<int,string>(7,"小乔"));
	printMap(m);
	return 0;
}
