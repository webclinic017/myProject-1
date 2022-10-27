#include <iostream>
using namespace std;
#include <map>
/*
map容器的特点：
	1.map容器中所有的值都是pair
	2.pair 第一为key值，第二为value值
	3.map会自动按照key值排序
优点:
	按照key值查找非常非常快。
*/

void printMap(const map<int,string> &m) {
	for (map<int,string>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << "序号：" << it->first << " 姓名：" << it->second << endl;
	};
	cout << endl << endl;
};

int main() {
	// 1.默认构造
	map<int, string> m1;
	m1.insert(pair<int,string>(3,"张飞"));
	m1.insert(pair<int,string>(1,"刘备"));
	m1.insert(pair<int,string>(3,"张飞"));
	m1.insert(pair<int,string>(2,"关羽"));
	m1.insert(pair<int,string>(1,"刘备"));
	
	printMap(m1);

	// 2.拷贝构造
	map<int,string> m2(m1);
	printMap(m2);

	// 3.operator=赋值操作
	map<int,string> m3;
	m3 = m2;
	printMap(m3);

	return 0;
}
