#include <iostream>
using namespace std;
#include <map>
/*

*/
void printMap(const map<int,string> &m) {
	for (map<int,string>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << "序号：" << it->first << " 姓名：" << it->second << endl;
	};
	cout << endl;
};

int main() {
	map<int,string> m1;
	cout << "m1是否empty：" << m1.empty() << endl;
	cout << "m1的size："   << m1.size() << endl;
	m1.insert(make_pair(1,"刘备"));
	m1.insert(make_pair(2,"关羽"));	
	m1.insert(make_pair(3,"张飞"));	
	m1.insert(make_pair(4,"赵云"));
	cout << "m1是否empty：" << m1.empty() << endl;
	cout << "m1的size："   << m1.size() << endl << endl;

	map<int, string> m2;
	m2.insert(pair<int,string>(5,"貂蝉"));
	m2.insert(pair<int,string>(6,"大乔"));
	m2.insert(pair<int,string>(7,"小乔"));

	cout << "交换前：" << endl;
	printMap(m1); printMap(m2);

	m1.swap(m2);

	cout << "交换后：" << endl;
	printMap(m1); printMap(m2);
	return 0;
}
