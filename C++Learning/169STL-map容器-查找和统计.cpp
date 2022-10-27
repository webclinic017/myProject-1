#include <iostream>
using namespace std;
#include <map>
/*
find(key)
count(key)
*/

int main() {
	map<int,string> m;
	m.insert(make_pair(1,"刘备"));
	m.insert(make_pair(2,"关羽"));	
	m.insert(make_pair(3,"张飞"));	
	m.insert(make_pair(4,"赵云"));
	m.insert(pair<int,string>(5,"貂蝉"));
	m.insert(pair<int,string>(6,"大乔"));
	m.insert(pair<int,string>(7,"小乔"));

	map<int, string>::iterator pos1 = m.find(6);
	if (pos1 != m.end()) {
		cout << "找到人了，是 " << pos1->second << endl;
	}
	else {
		cout << "没找到人。" << endl;
	};

	map<int, string>::iterator pos2 = m.find(9);
	if (pos2 != m.end()) {
		cout << "找到人了，是 " << pos2->second << endl;
	}
	else {
		cout << "没找到人。" << endl;
	};
	
	cout << "编号为1的人数：" << m.count(1) << endl;
	cout << "编号为10的人数：" << m.count(10) << endl;

	return 0;
}
